#include <cstdint>
#include <iostream>

std::uint32_t sum(std::uint32_t n)
{
    if (n > 1)
        return n + sum(n - 1);

    return n;
}

int main()
{
    std::uint32_t n = 10; // 0..10
    std::uint32_t s = sum(n);

    std::cout << "Sum from 0..10: " << s << std::endl;
    // (n^2 + n) / 2
    // (100 + 10) / 2

    return 0;
}
