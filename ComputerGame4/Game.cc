#include <cstdint>
#include <iostream>

#include "Game.h"

void print_game_state(const std::uint32_t player)
{
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
}

void execute_move(std::uint32_t &player, const char move)
{
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

bool is_finished(const std::uint32_t player)
{
    return player == GOAL;
}

void game()
{
    std::uint32_t player = 0;
    char move = 0;

    while (true)
    {
        if (is_finished(player))
        {
            break;
        }

        std::cin >> move;

        execute_move(player, move);
    }
}
