#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

auto print = [](auto const &view) {
    for (std::cout << "{ "; const auto element : view)
        std::cout << element << ' ';
    std::cout << "} ";
};

int main()
{
    // Drop, Take, Transform,
    auto numbers1 = std::vector<int>{1, 2, 3, 4, 5, 6};
    auto results1 = std::views::reverse(numbers1) | std::views::drop(2) |
                    std::views::take(3) |
                    std::views::transform([](const auto n) { return n * 2; }) |
                    std::views::filter([](const auto n) { return n % 2 == 0; });

    for (auto v : numbers1)
        std::cout << v << " ";
    std::cout << std::endl;

    for (auto v : results1)
        std::cout << v << " ";
    std::cout << std::endl;

    // Filter, Transform
    auto numbers2 = std::vector<int>{1, 2, 3, 4, 5, 6};
    auto results2 = numbers2 | std::views::filter([](int n) { return n % 2 == 0; }) |
                    std::views::transform([](int n) { return n * 2; });

    for (auto v : results2)
        std::cout << v << " ";
    std::cout << std::endl;

    // Split
    constexpr auto hello = std::string_view{"Hello C++ 20 !"};
    auto res = hello | std::ranges::views::split(' ');
    std::cout << "substrings: ";
    std::ranges::for_each(res, print);

    return 0;
}
