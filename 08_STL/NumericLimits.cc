#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>

template <typename T>
void print_type_properties()
{
    std::cout << "min=" << std::numeric_limits<T>::min() << '\n'
              << "max=" << std::numeric_limits<T>::max() << '\n'
              << "bits=" << std::numeric_limits<T>::digits << '\n'
              << "decdigits=" << std::numeric_limits<T>::digits10 << '\n'
              << "integral=" << std::boolalpha
              << std::numeric_limits<T>::is_integer << '\n'
              << "signed=" << std::boolalpha
              << std::numeric_limits<T>::is_signed << '\n'
              << "exact=" << std::boolalpha << std::numeric_limits<T>::is_exact
              << '\n'
              << "infinity=" << std::boolalpha
              << std::numeric_limits<T>::has_infinity << '\n'
              << '\n';
}

template <typename T>
bool equal(const T x, const T y)
{
    return x == y;
}

template <typename T>
bool almost_equal(const T x, const T y)
{
    return std::abs(x - y) <= std::numeric_limits<T>::epsilon();
}

int main()
{
    print_type_properties<std::uint16_t>();
    print_type_properties<std::int32_t>();
    print_type_properties<float>();

    const auto d1 = 0.2;
    const auto d2 = 1.0 / (std::sqrt(5.0) * std::sqrt(5.0)); // == 1 / 5

    std::cout << d1 << '\n';
    std::cout << d2 << '\n';

    std::cout.precision(17);

    std::cout << d1 << '\n';
    std::cout << d2 << '\n';

    std::cout << "d1 == d2? " << std::boolalpha << equal(d1, d2) << '\n';

    std::cout << "epsilon = " << std::numeric_limits<float>::epsilon() << '\n';
    std::cout << "d1 ~= d2? " << std::boolalpha << almost_equal(d1, d2) << '\n';

    return 0;
}
