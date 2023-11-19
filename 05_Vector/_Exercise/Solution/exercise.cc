#include <algorithm>
#include <iostream>
#include <vector>

#include "exercise.h"

// Exercise 2
VectorT max_row_values(MatrixT &matrix)
{
    auto row_max_vec = VectorT(matrix.size(), 0.0);
    if (!matrix.size() || !matrix[0].size())
        return row_max_vec;

    for (std::size_t i = 0; i != matrix.size(); ++i)
    {
        auto act_row_max = matrix[i][0];

        for (std::size_t j = 1; j != matrix[i].size(); ++j)
        {
            if (matrix[i][j] > act_row_max)
            {
                act_row_max = matrix[i][j];
            }
        }

        row_max_vec[i] = act_row_max;
    }

    return row_max_vec;
}

// Exercise 3
ValueT sort_and_max(VectorT &vec)
{
    std::sort(vec.begin(), vec.end());

    return vec.back();
}
