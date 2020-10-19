#include "matrix_multiplication.h"

using namespace std;

void run(int block_size, matrix_t m1, matrix_t m2, ComputationType type, fstream &fout) {
    Timer::start();
    if (block_size == 1) {
        simple_multiply(m1, m2, type);
    } else {
        block_multiply(m1, m2, block_size, type);
    }
    fout << setprecision(3) << Timer::end() << " ";
}

int main(int argc, char *argv[]) {
    const string USAGE = "Error. Usage is:\n./lab1 -n <size> -r <block_size> [-o <out_file>='output.txt']\n";

    if (argc < 7) {
        cerr << USAGE;
        return 1;
    }

    size_t n1, n2, block_size;
    string filename = "output.txt";

    for (size_t i = 1; i < argc; i += 2) {
        if (string(argv[i]) == "-n") {
            n2 = n1 = atoi(argv[i + 1]);
        } else if (string(argv[i]) == "-r") {
            block_size = atoi(argv[i + 1]);
        } else if (string(argv[i]) == "-o") {
            filename = argv[i + 1];
        } else {
            cerr << USAGE;
            return 1;
        }
    }

    int n3 = n1;
    fstream fout;
    fout.open(filename, fstream::out | fstream::app);
    omp_set_dynamic(0);
    omp_set_num_threads(8);

    matrix_t m1 = get_random_matrix(n1, n2);
    matrix_t m2 = get_random_matrix(n2, n3);
    matrix_t m3(n1, vector<int>(n3, 0));

    fout << block_size << " ";

    run(block_size, m1, m2, ComputationType::Linear, fout);
    run(block_size, m1, m2, ComputationType::InnerParallel, fout);
    run(block_size, m1, m2, ComputationType::OuterParallel, fout);

    fout << endl;
    return 0;
}

