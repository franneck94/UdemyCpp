#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    // 2d-Array (Matrix)
    // Number of rows = 3
    // Number of columns = 2
    std::int32_t my_matrix2[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    for (std::size_t i = 0; i < 3; i++)
    {
        for (std::size_t j = 0; j < 2; j++)
        {
            std::cout << my_matrix2[i][j] << '\n';
        }
    }

    // auto my_vector =
    //     std::vector<std::vector<std::int32_t>>{{1, 2}, {3, 4}, {5, 6}};
    auto my_vector =
        std::vector<std::vector<std::int32_t>>(3,
                                               std::vector<std::int32_t>(2, 0));

    for (const auto &row : my_vector)
    {
        for (const auto val : row)
        {
            std::cout << val << '\n';
        }
    }

    return 0;
}
