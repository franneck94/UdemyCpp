#include <algorithm>
#include <iostream>
#include <vector>

#include "exercise.h"

// Exercise 2
std::vector<double> max_row_values(Matrix &matrix)
{
    auto row_max_vec = std::vector<double>(matrix.size(), 0.0);

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
double sort_and_max(std::vector<double> &vec)
{
    std::sort(vec.begin(), vec.end());

    return vec.back();
}
