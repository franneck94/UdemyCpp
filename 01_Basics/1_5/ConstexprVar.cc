#include <cstdint>
#include <iostream>

const std::uint32_t NUM_PLAYERS1 = 2U;
constexpr std::uint32_t NUM_PLAYERS2 = 2U;

int main()
{
    for (std::uint32_t i = 0; i < NUM_PLAYERS1; ++i)
    {
        std::cout << "Hi\n";
    }

    return 0;
}
