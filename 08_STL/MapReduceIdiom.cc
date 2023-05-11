#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void print_vector(const std::vector<double> &vec)
{
    for (const auto &val : vec)
    {
        std::cout << val << '\n';
    }

    std::cout << '\n';
}

double magnitude(std::vector<double> vec)
{
    // 1.) Map: Square all values
    std::transform(vec.begin(), vec.end(), vec.begin(), [](const auto value) {
        return std::pow(value, 2.0);
    });

    // 2.) Reduce
    const auto sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return std::sqrt(sum);
}

int main()
{
    auto my_vector = std::vector<double>(3, 0);
    std::iota(my_vector.begin(), my_vector.end(), 1);
    print_vector(my_vector);

    std::cout << "Magnitude: " << magnitude(my_vector) << '\n';

    return 0;
}
