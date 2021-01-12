#include <iostream>
#include <vector>
#include <span>

int main()
{
    std::vector a{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    std::vector b{ 8, 7, 6 };
 
    std::span span_a(a.begin() + 1, a.end() - 1);

    for (auto v: span_a) std::cout << v << " ";
    std::cout << std::endl;

    std::span span_b{b};

    for (auto v: span_b) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}