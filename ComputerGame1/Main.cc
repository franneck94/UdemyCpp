#include <cstdint>
#include <iostream>

int main()
{
    std::uint32_t START = 0;
    std::uint32_t GOAL = 9;
    char LEFT = 'a';
    char RIGHT = 'd';

    std::uint32_t player = 0;
    char move = 0;
    std::cin >> move;

    if (LEFT == move && player > START)
    {
        std::cout << "The player moved to the left!" << std::endl;
    }
    else if (RIGHT == move && player < GOAL)
    {
        std::cout << "The player moved to the right!" << std::endl;
    }
    else
    {
        std::cout << "Unrecognized move!" << std::endl;
    }

    return 0;
}
