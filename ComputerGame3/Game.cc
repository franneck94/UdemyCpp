#include <cstdint>
#include <iostream>

#include "Game.h"

void game()
{
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
            player--;
        }
        else if (RIGHT == move && player < (LEN_X - 1))
        {
            player++;
        }
        else
        {
            std::cout << "Unrecognized move!\n";
        }
    }
}
