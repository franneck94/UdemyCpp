#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    int matrix[2][4]{};

    for (const auto &row : matrix)
    {
        for (const auto &element : row)
        {
            std::cout << element << "\n";
        }
    }

    struct Data
    {
        int x;
        int y;
    };

    Data array[] = {{1, 2}, {5, 6}, {7, 1}};

    for (const auto &[x1, y1] : array)
    {
        std::cout << x1 << "," << y1 << "\n";
    }

    return 0;
}
