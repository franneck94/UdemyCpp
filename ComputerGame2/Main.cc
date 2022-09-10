#include <cstdint>
#include <iostream>

int main()
{
    std::uint32_t LEN_X = 10U;
    std::uint32_t START = 0U;
    std::uint32_t GOAL = 9U;
    char LEFT = 'a';
    char RIGHT = 'd';

    std::uint32_t player = START;
    char move;

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
            std::cout << "The player moved to the left!\n";
            player--;
        }
        else if (RIGHT == move && player < (LEN_X - 1))
        {
            std::cout << "The player moved to the right!\n";
            player++;
        }
        else
        {
            std::cout << "Unrecognized move!\n";
        }
    }

    return 0;
}
