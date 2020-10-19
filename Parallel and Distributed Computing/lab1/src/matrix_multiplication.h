#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <omp.h>

#include "utils.h"

using namespace std;

enum class ComputationType {
    Linear,
    InnerParallel,
    OuterParallel,
};

matrix_t simple_multiply(matrix_t &, matrix_t &, ComputationType = ComputationType::Linear);

matrix_t block_multiply(matrix_t &, matrix_t &, int, ComputationType = ComputationType::Linear);

