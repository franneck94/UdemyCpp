#include <iostream>
#include <span>
#include <vector>

int main()
{
    // span with static extent
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::span<int, 9> span_a{arr};

    for (auto v : span_a)
        std::cout << v << " ";
    std::cout << std::endl;

    // spans with dynamic extent
    std::vector a{0, 1, 2, 3, 4, 5, 6, 7, 8};

    std::span span_b(a.begin() + 1, a.end() - 1);

    for (auto v : span_b)
        std::cout << v << " ";
    std::cout << std::endl;

    std::span span_c = span_b.subspan(1, 5);

    for (auto v : span_c)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
