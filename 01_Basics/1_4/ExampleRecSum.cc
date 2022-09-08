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
    std::uint32_t n = 10;
    std::uint32_t n_sum = sum(n);

    std::cout << "Sum from 0..10: " << n_sum << std::endl;

    return 0;
}
