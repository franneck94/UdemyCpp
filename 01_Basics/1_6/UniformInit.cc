#include <iostream>

int main()
{
    auto k = 10.0;

    // Bad
    int m = k;
    std::cout << m << std::endl;

    // Semi-Bad
    auto n = static_cast<int>(k);
    std::cout << n << std::endl;

    // Good
    // Uniform Init.
    auto l = int{k};
    std::cout << l << std::endl;

    return 0;
}
