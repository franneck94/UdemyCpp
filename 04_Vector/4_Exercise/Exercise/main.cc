#include <algorithm>
#include <iostream>
#include <vector>

#include "exercise.h"

int main()
{
    // Exercise 1
    auto matrix = Matrix(3, std::vector<double>(3, 0.0));

    for (std::size_t i = 0; i != matrix.size(); ++i)
    {
        for (std::size_t j = 0; j != matrix[i].size(); ++j)
        {
            matrix[i][j] = static_cast<double>(i + j);
        }
    }
    std::cout << '\n';

    for (std::size_t i = 0; i != matrix.size(); ++i)
    {
        for (std::size_t j = 0; j != matrix[i].size(); ++j)
        {
            std::cout << "i = " << i << " , j = " << j
                      << ", matrix = " << matrix[i][j] << '\n';
        }
    }
    std::cout << '\n';

    // Exercise 2
    auto row_max_vec = max_row_values(matrix);

    for (std::size_t i = 0; i != row_max_vec.size(); ++i)
    {
        std::cout << "Maximum of row " << i << " = " << row_max_vec[i] << '\n';
    }
    std::cout << '\n';

    // Exercise 3
    auto temp = row_max_vec[2];
    row_max_vec[2] = row_max_vec[1];
    row_max_vec[1] = temp;

    for (std::size_t i = 0; i != row_max_vec.size(); ++i)
    {
        std::cout << "Vector[" << i << "] = " << row_max_vec[i] << '\n';
    }
    std::cout << '\n';

    const auto max = sort_and_max(row_max_vec);

    for (std::size_t i = 0; i != row_max_vec.size(); ++i)
    {
        std::cout << "Sorted vector[" << i << "] = " << row_max_vec[i] << '\n';
    }
    std::cout << '\n';

    std::cout << "Vector max: " << max << '\n';

    return 0;
}
