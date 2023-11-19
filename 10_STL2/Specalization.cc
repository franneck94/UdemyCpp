#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
std::size_t length(const std::vector<T> &vec)
{
    return vec.size();
}

template <>
std::size_t length(const std::vector<std::string> &vec)
{
    return std::accumulate(vec.begin(),
                           vec.end(),
                           0,
                           [](const auto prev_len, const auto &str) {
                               return prev_len + str.size();
                           });
}

int main()
{
    const auto vec1 = std::vector<int>{1, 2, 3};
    std::cout << length(vec1) << '\n';

    const auto vec2 = std::vector<std::string>{"11", "2", "3"};
    std::cout << length(vec2) << '\n';

    return 0;
}
