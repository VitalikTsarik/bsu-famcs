#include "matrix_multiplication.h"

matrix_t simple_multiply(matrix_t &m1, matrix_t &m2, ComputationType type) {
    size_t n1 = m1.size();
    size_t n2 = m1[0].size();
    size_t n3 = m2[0].size();
    matrix_t result(n1, vector<int>(n3, 0));

#pragma omp parallel for if (type == ComputationType::OuterParallel)
    for (size_t i = 0; i < n1; i++) {
#pragma omp parallel for if (type == ComputationType::InnerParallel)
        for (size_t j = 0; j < n3; j++) {
            for (size_t k = 0; k < n2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

matrix_t block_multiply(matrix_t &m1, matrix_t &m2, int block_size, ComputationType type) {
    size_t n1 = m1.size();
    size_t n2 = m2[0].size();
    size_t n3 = m1[0].size();
    matrix_t result(n1, vector<int>(n3, 0));

#pragma omp parallel for if (type == ComputationType::OuterParallel)
    for (size_t bi = 0; bi < n1; bi += block_size) {
#pragma omp parallel for if (type == ComputationType::InnerParallel)
        for (size_t bj = 0; bj < n2; bj += block_size) {
            for (size_t bk = 0; bk < n3; bk += block_size) {
                for (size_t i = 0; i < block_size; i++) {
                    for (size_t j = 0; j < block_size; j++) {
                        for (size_t k = 0; k < block_size; k++) {
                            result[bi + i][bj + j] += m1[bi + i][bk + k] * m2[bk + k][bj + j];
                        }
                    }
                }
            }
        }
    }
    return result;
}