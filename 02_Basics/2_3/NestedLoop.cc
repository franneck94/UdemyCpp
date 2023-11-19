#include <cstdint>
#include <iostream>

int main()
{
    for (std::uint32_t i = 0; i < 2; i++)
    {
        for (std::uint32_t j = 0; j < 4; j++)
        {
            std::cout << i * j << std::endl;
        }
    }

    return 0;
}
