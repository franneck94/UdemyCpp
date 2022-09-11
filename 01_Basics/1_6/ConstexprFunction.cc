#include <cstdint>
#include <iostream>

const std::uint32_t NUM_PLAYERS1 = 2U;
constexpr std::uint32_t NUM_PLAYERS2 = 2U;

constexpr unsigned int faculty(unsigned int n)
{
    if (n > 1)
    {
        return n * faculty(n - 1);
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    constexpr std::uint32_t n = 5;
    constexpr std::uint32_t result = faculty(n);

    std::cout << result << std::endl;

    return 0;
}
