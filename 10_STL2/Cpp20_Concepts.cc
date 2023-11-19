#include <concepts>
#include <iostream>
#include <string>

template <typename T>
concept LessComp = requires(T x, T y) { x < y; };

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <typename T>
concept NumComp = Numeric<T> && LessComp<T>;

template <typename T, typename U>
    requires NumComp<T> && NumComp<U>
auto max1(const T &a, const U &b)
{
    return a < b ? b : a;
}

template <NumComp T, NumComp U>
auto max2(const T &a, const U &b)
{
    return a < b ? b : a;
}

int main()
{
    std::cout << max1(10, 11) << '\n';
    std::cout << max1(10.0F, 11.0F) << '\n';
    std::cout << max1(10.0, 11.0) << '\n';

    std::cout << max2(10, 11) << '\n';
    std::cout << max2(10.0F, 11.0F) << '\n';
    std::cout << max2(10.0, 11.0) << '\n';

    return 0;
}
