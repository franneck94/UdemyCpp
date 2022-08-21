#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

template <typename T>
void print_min_max()
{
    std::cout << "min: " << std::dec << std::numeric_limits<T>::min()
              << " max: " << std::dec << std::numeric_limits<T>::max() << std::endl;
}

bool equal(double x, double y)
{
    return x == y;
}

bool almost_equal(float x, float y)
{
    return std::abs(x - y) <= std::numeric_limits<float>::epsilon();
}

int main()
{
    print_min_max<short>();
    print_min_max<int>();
    print_min_max<float>();
    print_min_max<double>();

    double d1 = 0.2;
    double d2 = 1 / (std::sqrt(5) * std::sqrt(5)); // == 1 / 5

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    std::cout.precision(17);

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    std::cout << "d1 == d2? " << std::boolalpha << equal(d1, d2) << std::endl;

    std::cout << "epsilon = " << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << "d1 ~= d2? " << std::boolalpha << almost_equal(d1, d2) << std::endl;

    return 0;
}
