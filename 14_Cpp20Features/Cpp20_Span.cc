#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

void f(std::span<std::uint32_t> span)
{
    for (const auto v : span)
        std::cout << v << " ";
    std::cout << std::endl;
}

int main()
{
    static constexpr std::size_t LEN = 9;

    // span with static extent
    std::uint32_t arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto arr2 = std::array<std::uint32_t, LEN>{0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto vec = std::vector<std::uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8};
    f(arr1);
    f(arr2);
    f(vec);

    // spans with dynamic extent
    auto span = std::span(vec.begin(), vec.end());
    const auto span2 = span.subspan(1, 5);
    f(span2);

    return 0;
}
