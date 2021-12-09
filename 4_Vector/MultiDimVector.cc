#include <iostream>
#include <vector>

int main()
{
    const std::size_t num_rows = 3;
    const std::size_t num_cols = 2;

    // 2d-array (3x2 matrix)
    int arr[num_rows][num_cols] = {{0, 1}, {2, 3}, {4, 5}};

    for (std::size_t i = 0; i < num_rows; ++i)
    {
        for (std::size_t j = 0; j < num_cols; ++j)
        {
            std::cout << "arr[" << i << ", " << j << "] = " << arr[i][j] << std::endl;
        }
    }

    // 2d-vector (3x2 matrix) => 3 Rows, 2 Columns
    //                                       NUM_OF: std::vector<int>     VALUE OF: std::vector<int>
    std::vector<std::vector<int>> my_vector(num_rows, std::vector<int>(num_cols, 0));

    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        for (std::size_t j = 0; j < my_vector[i].size(); ++j)
        {
            my_vector[i][j] = static_cast<int>(i * j + i + j);
        }
    }

    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        // my_vector[i] => Row-vector with 2 int values
        for (std::size_t j = 0; j < my_vector[i].size(); ++j)
        {
            std::cout << "my_vector[" << i << ", " << j << "] = " << my_vector[i][j] << std::endl;
        }
    }

    return 0;
}
