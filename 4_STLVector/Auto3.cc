#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    int matrix[2][3]{};

    for (const auto &row : matrix)
    {
        for (const auto &value : row)
        {
            std::cout << value << std::endl;
        }
    }

    struct Data
    {
        int x;
        int y;
    };

    std::vector<Data> vec{{1, 2}, {4, 6}, {8, 9}};

    for (const auto &[x1, y1] : vec)
    {
        std::cout << x1 << y1 << std::endl;
    }

    return 0;
}
