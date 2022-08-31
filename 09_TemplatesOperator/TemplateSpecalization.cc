#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
struct is_numeric
    : public std::disjunction<std::is_integral<T>, std::is_floating_point<T>>
{
};

template <typename T>
std::size_t length(const std::vector<T> &vec)
{
    static_assert(is_numeric<T>::value, "failed...");

    return vec.size();
}

template <>
std::size_t length(const std::vector<std::string> &vec)
{
    auto l = std::size_t{};

    for (const auto &s : vec)
    {
        l += s.size();
    }

    return l;
}

int main()
{
    const auto vec1 = std::vector<int>{1, 2, 3};
    std::cout << length(vec1) << '\n';

    const auto vec2 = std::vector<std::string>{"11", "2", "3"};
    std::cout << length(vec2) << '\n';

    return 0;
}
