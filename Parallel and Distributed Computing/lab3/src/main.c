#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOT 0

int N;
int size;
int rank;
int R2, Q2, R2_last, R2_global;
int R3, Q3;

double **A;
double **submatrix;
double **B;
double *underA;
double *underB;
double *underSubmatrix;

clock_t startTime;
double communicationTime = 0;
double calculationTime = 0;
double backwardSubstitutionTime = 0;

void updateTimeComm() {
    communicationTime += (double) (clock() - startTime);
}

void updateTimeCalc() {
    calculationTime += (double) (clock() - startTime);
}

void generateMatrix() {
    underA = (double *) malloc(N * (N + 1) * sizeof(double));
    A = (double **) malloc((N) * sizeof(double *));
    for (int i = 0; i < N; i++) {
        A[i] = underA + i * (N + 1);
    }

    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < N; j++) {
            A[i][j] = (i == j ? 100. : (2. * i + j) / 100000.);
            sum += A[i][j];
        }
        A[i][N] = sum;
    }
}

void alloc_B() {
    underB = (double *) malloc(N * (N + 1) * sizeof(double));
    B = (double **) malloc((N) * sizeof(double *));
    for (int i = 0; i < N; i++) {
        B[i] = underB + i * (N + 1);
    }
}

long double calcError() {
    long double mx_norm = 0.;
    for (int i = 0; i < N; i++) {
        long double val = 0;
        for (int j = 0; j < N; j++) {
            val += A[i][j] * B[j][N];
        }
        long double fa = fabsl(val - A[i][N]);
        if (fa > mx_norm) {
            mx_norm = fa;
        }
    }
    return mx_norm;
}

void forwardElimination(int rank) {
    for (int k = 0; k < N; k++) {
        int row = k % R2_global;
        double el;

        if (rank == k / R2_global) el = submatrix[row][k];

        for (int j_gl = 0; j_gl < Q3; j_gl++) {
            int width = (j_gl == Q3 - 1 ? N + 1 - R3 * (Q3 - 1) : R3);
            int offset = j_gl * R3; // for U vector.

            double *u = (double *) calloc(width, sizeof(double));

            if (rank == k / R2_global) {
                startTime = clock();
                for (int j = j_gl * R3; j < j_gl * R3 + R3 && j < N + 1; j++) {
                    if (j < k + 1)
                        continue;
                    u[j - offset] = submatrix[row][j] / el;
                    submatrix[row][j] /= el;
                }

                if (k >= j_gl * R3 && k <= j_gl * R3 + R3) {
                    u[k - offset] = 1.;
                    submatrix[row][k] = 1.;
                }

                updateTimeCalc();

                startTime = clock();
                if (rank != Q2 - 1) {
                    MPI_Send(u, width, MPI_DOUBLE, rank + 1, 123, MPI_COMM_WORLD);
                }
                updateTimeComm();

                startTime = clock();
                for (int i = row + 1; i < R2; i++) {
                    for (int j = j_gl * R3; j < j_gl * R3 + R3 && j < N + 1; j++) {
                        if (j < k + 1) continue;
                        submatrix[i][j] -= submatrix[i][k] * u[j - offset];
                    }
                }

                if (j_gl == Q3 - 1) {
                    for (int i = row + 1; i < R2; i++) {
                        submatrix[i][k] = 0.;
                    }
                }

                updateTimeCalc();

            } else if (rank > k / R2_global) {
                startTime = clock();
                MPI_Recv(u, width, MPI_DOUBLE, rank - 1, 123, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                if (rank < Q2 - 1) {
                    MPI_Send(u, width, MPI_DOUBLE, rank + 1, 123, MPI_COMM_WORLD);
                }
                updateTimeComm();

                startTime = clock();
                for (int i = 0; i < R2; i++) {
                    for (int j = j_gl * R3; j < j_gl * R3 + R3 && j < N + 1; j++) {
                        if (j < k + 1) continue;
                        submatrix[i][j] -= submatrix[i][k] * u[j - offset];
                    }
                }

                if (j_gl == Q3 - 1) {
                    for (int i = 0; i < R2; i++) {
                        submatrix[i][k] = 0.;
                    }
                }
                updateTimeCalc();
            }
            MPI_Barrier(MPI_COMM_WORLD);
        }
    }
}

void backwardSubstitution() {
    for (int k = N - 1; k >= 1; k--) {
        for (int j = k - 1; j >= 0; j--) {
            B[j][N] -= B[j][k] * B[k][N];
            B[j][k] = 0;
        }
    }
}

int main(int argc, char **argv) {
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (argc != 3) {
        if (rank == ROOT) {
            printf("Required number of arguments: 3\n");
        }
        return 1;
    }

    clock_t begin_time_total;
    if (rank == ROOT) {
        begin_time_total = clock();
    }

    MPI_Barrier(MPI_COMM_WORLD);

    sscanf(argv[1], "%d", &N);

    Q2 = size;
    R2 = ceil(N * 1. / Q2);

    R2_global = R2;
    R2_last = N - R2 * (Q2 - 1);
    if (rank == Q2 - 1) {
        R2 = R2_last;
    }

    sscanf(argv[2], "%d", &R3);
    Q3 = ceil((N + 1) * 1. / R3);

    if (rank == ROOT) {
        printf(
                "\nrunning with parameters:\n"
                "Q2: %d  R2: %d\n"
                "Q3: %d  R3: %d\n", Q2, R2, Q3, R3);
    }

    underSubmatrix = malloc(R2 * (N + 1) * sizeof(double));
    submatrix = malloc(R2 * sizeof(double *));
    for (int i = 0; i < R2; i++) {
        submatrix[i] = underSubmatrix + i * (N + 1);
    }

    if (rank == ROOT) {
        generateMatrix();

        startTime = clock();
        for (int proc = 1; proc < Q2 - 1; proc++) {
            MPI_Send(A[R2 * proc], R2 * (N + 1), MPI_DOUBLE, proc, 345, MPI_COMM_WORLD);
        }
        if (Q2 > 1) {
            MPI_Send(A[R2 * (Q2 - 1)], R2_last * (N + 1), MPI_DOUBLE, Q2 - 1, 345, MPI_COMM_WORLD);
        }
        updateTimeComm();
        for (int i = 0; i < R2; i++) {
            for (int j = 0; j < N + 1; j++) {
                submatrix[i][j] = A[i][j];
            }
        }
    } else {
        startTime = clock();
        MPI_Recv(underSubmatrix, R2 * (N + 1), MPI_DOUBLE, ROOT, 345, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        updateTimeComm();
    }

    MPI_Barrier(MPI_COMM_WORLD);

    forwardElimination(rank);

    MPI_Barrier(MPI_COMM_WORLD);

    if (rank == ROOT) {
        alloc_B();
        startTime = clock();
        for (int proc = 1; proc < Q2 - 1; proc++) {
            MPI_Recv(B[R2 * proc], R2 * (N + 1), MPI_DOUBLE, proc, 109, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        if (Q2 > 1) {
            MPI_Recv(B[R2 * (Q2 - 1)], R2_last * (N + 1), MPI_DOUBLE, Q2 - 1, 109, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        updateTimeComm();
        for (int i = 0; i < R2; i++) {
            for (int j = 0; j < N + 1; j++) {
                B[i][j] = submatrix[i][j];
            }
        }
    } else {
        startTime = clock();
        MPI_Send(underSubmatrix, R2 * (N + 1), MPI_DOUBLE, ROOT, 109, MPI_COMM_WORLD);
        updateTimeComm();
    }

    MPI_Barrier(MPI_COMM_WORLD);

    printf("[%d] communication time:  %fs\n", rank, communicationTime / CLOCKS_PER_SEC);
    printf("[%d] calculation time:    %fs\n", rank, calculationTime / CLOCKS_PER_SEC);

    MPI_Barrier(MPI_COMM_WORLD);

    if (rank == ROOT) {
        startTime = clock();
        backwardSubstitution();
        backwardSubstitutionTime = (double) (clock() - startTime) / CLOCKS_PER_SEC;

        long double error = calcError();

        printf("Error: %.15Lf\n", error);
        printf("Total time: %fs\n", ((float) (clock() - begin_time_total) / CLOCKS_PER_SEC));
        printf("Backward substitution time: %fs\n", backwardSubstitutionTime);

        FILE *file = fopen("reports/output.txt", "a");
        fprintf(file, "%d %f %f\n", size, ((float) (clock() - begin_time_total) / CLOCKS_PER_SEC),
                backwardSubstitutionTime);
        fclose(file);
    }

    if (rank == ROOT) {
        free(underA);
        free(A);
        free(underB);
        free(B);
    }
    free(underSubmatrix);
    free(submatrix);

    MPI_Finalize();

    return 0;
}