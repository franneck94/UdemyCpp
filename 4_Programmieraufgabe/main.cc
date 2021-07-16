#include <algorithm>
#include <iostream>
#include <vector>

#include "exercise.h"

int main()
{
    // Exercise 1
    Matrix matrix(3, std::vector<double>(3, 0.0));

    for (unsigned int i = 0; i != matrix.size(); ++i)
    {
        for (unsigned int j = 0; j != matrix[i].size(); ++j)
        {
            matrix[i][j] = i + j;
        }
    }

    for (unsigned int i = 0; i != matrix.size(); ++i)
    {
        for (unsigned int j = 0; j != matrix[i].size(); ++j)
        {
            std::cout << std::endl << "i = " << i << " , j = " << j << ", matrix = " << matrix[i][j];
        }
    }
    std::cout << std::endl;

    // Exercise 2
    std::vector<double> row_max_vec = max_row_values(matrix);

    for (unsigned int i = 0; i != row_max_vec.size(); ++i)
    {
        std::cout << "Maximum of row " << i << " = " << row_max_vec[i] << std::endl;
    }

    // Exercise 3
    double temp = row_max_vec[2];
    row_max_vec[2] = row_max_vec[1];
    row_max_vec[1] = temp;

    for (unsigned int i = 0; i != row_max_vec.size(); ++i)
    {
        std::cout << "Vector[" << i << "] = " << row_max_vec[i] << std::endl;
    }

    double max = sort_and_max(row_max_vec);

    for (unsigned int i = 0; i != row_max_vec.size(); ++i)
    {
        std::cout << "Sorted vector[" << i << "] = " << row_max_vec[i] << std::endl;
    }

    std::cout << "Vector max: " << max << std::endl;

    return 0;
}
