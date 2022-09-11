#include <cstdint>
#include <iostream>

int main()
{
    const std::uint32_t num_players = 2U;

    for (std::uint32_t i = 0; i < num_players; ++i)
    {
        std::cout << "Hi\n";
    }

    return 0;
}
