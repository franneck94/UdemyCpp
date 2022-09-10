#include <cstdint>
#include <iostream>

#include "Game.h"

void print_game_state(std::uint32_t player)
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

std::uint32_t execute_move(std::uint32_t player, char move)
{
    if (LEFT == move && player > 0)
    {
        return player - 1;
    }
    else if (RIGHT == move && player < GOAL)
    {
        return player + 1;
    }
    else
    {
        return player;
    }
}

bool is_finished(std::uint32_t player)
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

        print_game_state(player);
        std::cin >> move;
        player = execute_move(player, move);
    }
}
