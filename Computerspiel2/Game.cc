#include <iostream>
#include <stdlib.h>

#include "Game.h"

constexpr unsigned int LEN_X = 10u;
constexpr unsigned int START = 0;
constexpr unsigned int GOAL = LEN_X - 1;

constexpr char LEFT = 'a';
constexpr char RIGHT = 'd';

void print_game_state(unsigned int player)
{
    char game_state[LEN_X];

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        game_state[i] = '.';
    }

    game_state[START] = '|';
    game_state[player] = 'P';
    game_state[GOAL] = '|';

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        std::cout << game_state[i] << " ";
    }
    std::cout << std::endl;
}

unsigned int execute_move(unsigned int player, char move)
{
    if (LEFT == move)
    {
        if (player > START)
        {
            player--;
            std::cout << "You moved to the left!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (RIGHT == move)
    {
        if (player < GOAL)
        {
            player++;
            std::cout << "You moved to the right!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else
    {
        std::cout << "Unrecognized move!" << std::endl;
    }

    return player;
}

bool is_finished(unsigned int player)
{
    if (player == GOAL)
    {
        std::cout << "You won the game!" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

void game()
{
    unsigned int player = 0;
    char move;
    bool finished = false;

    while (!finished)
    {
        print_game_state(player);
        std::cin >> move;
        system("clear");
        player = execute_move(player, move);
        finished = is_finished(player);
    }
}