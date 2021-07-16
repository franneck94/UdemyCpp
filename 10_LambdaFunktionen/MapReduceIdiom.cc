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
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
}

double magnitude(std::vector<double> &vec)
{
    // 1.) Map: sqaure all values
    std::transform(vec.begin(), vec.end(), vec.begin(), [](const double val) { return std::pow(val, 2.0); });

    // 2.) Reduce
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    const double root = std::pow(sum, 0.5);

    return root;
}

int main()
{
    std::vector<double> my_vector(10, 0.0);
    std::iota(my_vector.begin(), my_vector.end(), 0.0);

    print_vector(my_vector);

    std::cout << magnitude(my_vector) << std::endl;

    return 0;
}
