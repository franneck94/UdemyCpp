#include <cstdint>
#include <iostream>

#define NUM_PLAYERS 2
#define MODE_1

int main()
{
#ifdef MODE_1
    std::cout << "Num Players: " << NUM_PLAYERS << std::endl;
#else
    std::uint32_t num_players = 2;
    std::cout << "Num Players: " << num_players << std::endl;
#endif

    return 0;
}
