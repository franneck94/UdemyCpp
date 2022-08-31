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

double magnitude(std::vector<double> &vec)
{
    // 1.) Map: square all values
    std::transform(vec.begin(), vec.end(), vec.begin(), [](const double val) {
        return std::pow(val, 2.0);
    });

    // 2.) Reduce
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    const double root = std::pow(sum, 0.5);

    return root;
}

int main()
{
    auto my_vector = std::vector<double>(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);

    std::cout << magnitude(my_vector) << std::endl;

    return 0;
}
