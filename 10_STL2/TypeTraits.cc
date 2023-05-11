#include <iostream>
#include <type_traits>
#include <vector>

// template <typename T>
// T max(const T &a, const T &b)
// {
//     static_assert(
//         std::disjunction_v<std::is_integral<T>, std::is_floating_point<T>>,
//         "failed...");

//     return a < b ? b : a;
// }

// template <typename T>
// struct is_numeric
//     : public std::disjunction<std::is_integral<T>, std::is_floating_point<T>>
// {
// };

// template <typename T, typename U>
// T max(const T &a, const U &b)
// {
//     static_assert(std::conjunction_v<is_numeric<T>, is_numeric<U>>, "failed.");

//     return a < b ? b : a;
// }

template <typename T>
struct is_integral
{
    const static bool value = false;
};

template <>
struct is_integral<float>
{
    const static bool value = true;
};

template <>
struct is_integral<double>
{
    const static bool value = true;
};

template <typename T>
T max(const T &a, const T &b)
{
    static_assert(is_integral<T>::value, "failed.");

    return a < b ? b : a;
}

int main()
{
    std::cout << max(10, 11) << '\n';
    std::cout << max(10.0F, 11.0F) << '\n';
    std::cout << max(10.0, 11.0) << '\n';
    // std::cout << max<short>(10, 11) << '\n';

    // std::cout << max<short, short>(10, 11) << '\n';
    // std::cout << max<short, int>(10, 11) << '\n';
    // std::cout << max<int, short>(10, 11) << '\n';

    return 0;
}
