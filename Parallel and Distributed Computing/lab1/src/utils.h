#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

typedef vector<vector<int>> matrix_t;

class Timer {
private:
    static chrono::high_resolution_clock::time_point start_time;

public:
    static void start();

    static double end();
};

matrix_t get_random_matrix(size_t rows, size_t cols);

ostream &print_matrix(matrix_t &v);
