#include "utils.h"

chrono::high_resolution_clock::time_point Timer::start_time = chrono::high_resolution_clock::now();

void Timer::start() {
    start_time = chrono::high_resolution_clock::now();
}

double Timer::end() {
    auto end_time = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() / 1000.;
}

int get_random_number() {
    return (rand() % 200) - 100;
}

matrix_t get_random_matrix(size_t rows, size_t cols) {
    matrix_t v(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            v[i][j] = get_random_number();
        }
    }
    return v;
}
