#include <iostream>
#include <stdlib.h>

#include "Game.h"

constexpr unsigned int LEN_X = 5;
constexpr unsigned int LEN_Y = 5;
constexpr Position START = { 0, 0 };
constexpr Position GOAL = { LEN_X - 1, LEN_Y - 1 };

constexpr char LEFT = 'a';
constexpr char RIGHT = 'd';
constexpr char UP = 'w';
constexpr char DOWN = 's';

void print_game_state(Position player)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    game_state[START.first][START.second] = '|';
    game_state[GOAL.first][GOAL.second] = '|';
    game_state[player.first][player.second] = 'P';

    for (unsigned int i = 0; i < LEN_X; ++i)
    {
        for (unsigned int j = 0; j < LEN_Y; ++j)
        {
            std::cout << game_state[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

Position execute_move(Position player, ConsoleInput move)
{
    if (LEFT == move)
    {
        if (player.second > START.second)
        {
            player.second--;

            std::cout << "You moved to the left!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (RIGHT == move)
    {
        if (player.second < GOAL.second)
        {
            player.second++;

            std::cout << "You moved to the right!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (UP == move)
    {
        if (player.first > START.first)
        {
            player.first--;

            std::cout << "You moved up!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (move == DOWN)
    {
        if (player.first < GOAL.first)
        {
            player.first++;

            std::cout << "You moved down!" << std::endl;
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

bool is_finished(Position player)
{
    if (GOAL == player)
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
    Position player(0, 0);
    ConsoleInput move;
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
