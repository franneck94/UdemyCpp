#include <iostream>
#include <vector>

void print_matrix(const std::vector<std::vector<int>> &matrix)
{
    for (std::size_t i = 0; i < matrix.size(); i++)
    {
        for (std::size_t j = 0; j < matrix[i].size(); j++)
        {
            std::cout << "Matrix[" << i << "," << j << "] = " << matrix[i][j]
                      << std::endl;
        }
    }
    std::cout << std::endl;
}

int main()
{
    const std::size_t num_rows = 3;
    const std::size_t num_cols = 2;

    // int array[num_rows][num_cols] = {{0, 1,}, {2, 3}, {4, 5}};

    std::vector<std::vector<int>> matrix(num_rows, std::vector<int>(num_cols, 0));
    print_matrix(matrix);

    return 0;
}
