#include <concepts>
#include <iostream>
#include <string>

template <typename T>
concept Addable = requires(T x)
{
    x + x;
};

template <typename T>
concept NonNumeric = !std::integral<T> && !std::floating_point<T>;

template <typename T>
concept Concatenable = Addable<T> && NonNumeric<T>;

template <typename T>
requires Concatenable<T> T concat(T first, T second)
{
    return first + second;
}

int main()
{
    const auto s1 = std::string{"Hal"};
    const auto s2 = std::string{"lo"};

    std::cout << concat(s1, s2) << std::endl;

    return 0;
}
