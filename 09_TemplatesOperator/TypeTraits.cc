#include <iostream>
#include <type_traits>

// template <typename T>
// T max(const T &a, const T &b)
// {
//     static_assert(std::disjunction_v<std::is_integral<T>, std::is_floating_point<T>>,
//                   "failed...");

//     if (a < b)
//     {
//         return b;
//     }
//     else
//     {
//         return a;
//     }
// }

template <typename T>
struct is_numeric
    : public std::disjunction<std::is_integral<T>, std::is_floating_point<T>>
{
};

template <typename T, typename U>
T max(const T &a, const U &b)
{
    static_assert(std::conjunction_v<is_numeric<T>, is_numeric<U>>, "failed...");

    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    std::cout << max(10, 11) << std::endl;
    std::cout << max(10.0F, 11.0F) << std::endl;
    std::cout << max(10.0, 11.0) << std::endl;
    std::cout << max<short>(10, 11) << std::endl;
    std::cout << max<short, short>(10, 11) << std::endl;

    return 0;
}
