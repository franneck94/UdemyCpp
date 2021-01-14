#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include <string_view>

auto print = [](auto const& view) {
    for (std::cout << "{ "; const auto element : view)
        std::cout << element << ' ';
    std::cout << "} ";
};

int main()
{
    std::vector numbers1{1, 2, 3, 4, 5, 6};
    auto results1 = std::views::reverse(numbers1)
        | std::views::drop(2)
        | std::views::take(2)
        | std::views::transform([](const int n){return n * 2;});

    for (auto v: results1) std::cout << v << " ";
    std::cout << std::endl;

    std::vector<int> numbers2{1, 2, 3, 4, 5, 6};
    auto results2 = numbers2
        | std::views::filter([](int n){ return n % 2 == 0; })
        | std::views::transform([](int n){ return n * 2; });

    for (auto v: results2) std::cout << v << " ";
    std::cout << std::endl;

    constexpr std::string_view hello { "Hello C++ 20 !" };
    auto res = hello | std::ranges::views::split(' ');
    std::cout << "substrings: ";
    std::ranges::for_each(res, print);

    return 0;
}