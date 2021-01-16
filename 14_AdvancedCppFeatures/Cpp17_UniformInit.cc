#include <iostream>

#pragma GCC diagnostic ignored "-Wunused-variable"

int main()
{
    auto i { 2 };
    std::cout << i << std::endl;
    auto j = { 2 };
    // std::cout << j << std::endl;
    auto k { 2.0 };
    std::cout << k << std::endl;
    auto l = { 2.0 };
    // std::cout << l << std::endl;

    double m { 2.2 };
    std::cout << m << std::endl;
    float n { 2.0 };
    std::cout << n << std::endl;
    int o { m };
    std::cout << o << std::endl;
    // int p { 1.2 };

    return 0;
}