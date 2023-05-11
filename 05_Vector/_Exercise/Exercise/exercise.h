#pragma once

#include <vector>

using ValueT = double;
using VectorT = std::vector<ValueT>;
using MatrixT = std::vector<VectorT>;

// Exercise 2
VectorT max_row_values(MatrixT &matrix);

// Exercise 3
ValueT sort_and_max(VectorT &vec);
