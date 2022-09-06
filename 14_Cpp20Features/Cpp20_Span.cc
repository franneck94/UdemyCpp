#include <iostream>
#include <span>
#include <vector>

int main()
{
    // span with static extent
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    const auto span_a = std::span<int, 9>{arr};

    for (const auto v : span_a)
        std::cout << v << " ";
    std::cout << std::endl;

    // spans with dynamic extent
    auto a = std::vector{0, 1, 2, 3, 4, 5, 6, 7, 8};

    const auto span_b = std::span(a.begin() + 1, a.end() - 1);

    for (const auto v : span_b)
        std::cout << v << " ";
    std::cout << std::endl;

    const auto span_c = span_b.subspan(1, 5);

    for (const auto v : span_c)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
