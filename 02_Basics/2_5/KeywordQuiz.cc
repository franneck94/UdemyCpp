#include <cstdint>
#include <iostream>

constexpr float PI = 3.14159;

float circle_area(const float radius)
{
    return PI * radius * radius;
}

constexpr std::uint32_t sum(const std::uint32_t n)
{
    if (n > 1)
        return n + sum(n - 1);

    return n;
}

int main()
{
    constexpr std::uint32_t n = 10;
    constexpr std::uint32_t s = sum(n);

    std::cout << "Sum from 0..10: " << s << std::endl;

    return 0;
}
