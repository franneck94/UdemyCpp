#include <cstdint>
#include <iostream>

int main()
{
    std::uint32_t LEN_X = 10;
    std::uint32_t START = 0;
    std::uint32_t GOAL = 9;

    char LEFT = 'a';
    char RIGHT = 'd';

    std::uint32_t player = 0;
    char move = 0;

    while (true)
    {
        if (player == GOAL)
        {
            break;
        }

        for (std::uint32_t i = START; i < LEN_X; i++)
        {
            if (i == player)
            {
                std::cout << 'P';
            }
            else if (i == GOAL || i == START)
            {
                std::cout << '|';
            }
            else
            {
                std::cout << '.';
            }
        }

        std::cin >> move;

        if (LEFT == move && player > 0)
        {
            player--;
        }
        else if (RIGHT == move && player < GOAL)
        {
            player++;
        }
        else
        {
            std::cout << "Unrecognized move!" << std::endl;
        }
    }

    return 0;
}
