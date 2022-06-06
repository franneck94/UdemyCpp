#include <iostream>

#include "Game.h"

ConsoleInput map_user_input(char user_input)
{
    switch (user_input)
    {
    case 'w':
    {
        return ConsoleInput::UP;
    }
    case 'a':
    {
        return ConsoleInput::LEFT;
    }
    case 's':
    {
        return ConsoleInput::DOWN;
    }
    case 'd':
    {
        return ConsoleInput::RIGHT;
    }
    default:
    {
        return ConsoleInput::INVALID;
    }
    }
}

void print_game_state(Position player)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    game_state[START.first][START.second] = '|';
    game_state[GOAL.first][GOAL.second] = '|';
    game_state[player.first][player.second] = 'P';

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        for (unsigned int j = 0; j < LEN_Y; j++)
        {
            std::cout << game_state[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void execute_move(Position &player, ConsoleInput move)
{
    switch (move)
    {
    case ConsoleInput::LEFT:
    {
        if (player.second > 0)
        {
            player.second--;
        }
        break;
    }
    case ConsoleInput::RIGHT:
    {
        if (player.second < LEN_Y - 1)
        {
            player.second++;
        }
        break;
    }
    case ConsoleInput::UP:
    {
        if (player.first > 0)
        {
            player.first--;
        }
        break;
    }
    case ConsoleInput::DOWN:
    {
        if (player.first < LEN_X - 1)
        {
            player.first++;
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

bool is_finished(Position player)
{
    return player == GOAL;
}

void game()
{
    Position player = std::make_pair(0, 0);
    char user_input = 0;

    while (true)
    {
        if (is_finished(player))
        {
            break;
        }

        print_game_state(player);
        std::cin >> user_input;
        ConsoleInput console_input = map_user_input(user_input);
        execute_move(player, console_input);
    }
}
