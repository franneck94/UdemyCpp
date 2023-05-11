#include <cstdint>
#include <iostream>

int main()
{
    for (std::uint32_t i = 0; i < 3; i++)
    {
        std::cout << i << std::endl;
    }

    std::uint32_t i = 0;

    i = i + 1;
    i += 1;
    i++; // increment

    i = i - 1;
    i -= 1;
    i--; // decrement

    return 0;
}
