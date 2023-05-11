#include <cstdint>
#include <iostream>

int main()
{
    constexpr auto len = std::uint32_t{3U};

    float vector1[len]{};
    float vector2[len]{};

    for (std::uint32_t i = 0; i < len; ++i)
    {
        std::cout << vector1[i] << " ";
    }
    std::cout << '\n';

    for (std::uint32_t i = 0; i < len; ++i)
    {
        std::cout << vector2[i] << " ";
    }
    std::cout << '\n';

    std::cout << "Enter the values for vector 1: \n";
    for (std::uint32_t i = 0; i < len; ++i)
    {
        std::cin >> vector1[i];
    }

    std::cout << "Enter the values for vector 2: \n";
    for (std::uint32_t i = 0; i < len; ++i)
    {
        std::cin >> vector2[i];
    }

    for (std::uint32_t i = 0; i < len; ++i)
    {
        std::cout << "v1[i] + v2[i] = " << vector1[i] + vector2[i] << '\n';
    }

    return 0;
}
