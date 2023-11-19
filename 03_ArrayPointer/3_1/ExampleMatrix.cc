#include <cstdint>
#include <iostream>

// Compute the sum for every column

int main()
{
    constexpr static auto num_rows = std::uint32_t{3};
    constexpr static auto num_cols = std::uint32_t{2};

    std::int32_t my_matrix[num_rows][num_cols] = {{1, 2}, {3, 4}, {5, 6}};
    std::int32_t column_sums[num_cols]{};

    for (std::uint32_t i = 0; i < num_rows; ++i)
    {
        for (std::uint32_t j = 0; j < num_cols; ++j)
        {
            column_sums[j] += my_matrix[i][j];
        }
    }

    for (std::uint32_t j = 0; j < num_cols; ++j)
    {
        std::cout << "Sum at column " << j << " = " << column_sums[j] << '\n';
    }

    return 0;
}
