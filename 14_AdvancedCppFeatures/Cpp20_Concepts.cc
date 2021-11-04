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
concept Concatenable = Addable<T> &&NonNumeric<T>;

template <typename T>
requires Concatenable<T> T concat(T first, T second)
{
    return first + second;
}

int main()
{
    std::string s1 = "Ha";
    std::string s2 = "ll";
    std::string s3 = "o";

    std::cout << concat(s1, s2) << std::endl;
    // std::cout << concat(2, 3) << std::endl;

    return 0;
}
