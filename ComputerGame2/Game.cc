#include <iostream>

#include "Game.h"

void print_game_state(unsigned int player)
{
    for (unsigned int i = START; i < LEN_X; i++)
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

unsigned int execute_move(unsigned int player, char move)
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

bool is_finished(unsigned int player)
{
    return player == GOAL;
}

void game()
{
    unsigned int player = 0;
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
