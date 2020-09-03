#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>


// 0, 1, 2, 3, 4 (INPUT)
// 0, 1, 4, 9, 16 (SQUARE) = transform
// 30 (SUM) = accumulate
// 5,477 (SQRT)
double magnitude(std::vector<double> &vec)
{
    std::transform(vec.begin(), vec.end(), vec.begin(), [](double val) { return val * val; });
    return std::pow(std::accumulate(vec.begin(), vec.end(), 0.0), 0.5);
}

int main()
{
    std::vector<double> data(5, 0);
    std::iota(data.begin(), data.end(), 0); // 0, 1, 2, 3, 4

    std::cout << magnitude(data) << std::endl;

    return 0;
}