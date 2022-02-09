#include <iostream>
#include <type_traits>

template <typename T>
struct is_numeric : public std::disjunction<std::is_integral<T>, std::is_floating_point<T>>
{
};

template <typename T, typename U>
T max(T value_one, U value_two)
{
    static_assert(std::conjunction<is_numeric<T>, is_numeric<U>>::value, "failed...");

    if (value_one < value_two)
    {
        return value_two;
    }
    else
    {
        return value_one;
    }
}

template <typename T, typename U>
std::enable_if_t<!std::is_same<T, U>::value, typename std::common_type<T, U>::type> max(T value_one, U value_two)
{
    static_assert(std::conjunction<is_numeric<T>, is_numeric<U>>::value, "failed");

    if (static_cast<typename std::common_type<T, U>::type>(value_one) <
        static_cast<typename std::common_type<T, U>::type>(value_two))
    {
        return static_cast<typename std::common_type<T, U>::type>(value_two);
    }
    else
    {
        return static_cast<typename std::common_type<T, U>::type>(value_one);
    }
}

int main()
{
    int a = 2;
    int b = 3;

    std::cout << max(a, b) << std::endl;

    float c = 4.5f;
    float d = -1.0f;

    std::cout << max(c, d) << std::endl;

    double e = 3.7;
    double f = -1337.0;

    std::cout << max(e, f) << std::endl;

    // std::cout << max(a, f) << std::endl;

    return 0;
}
