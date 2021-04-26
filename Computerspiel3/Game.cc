#include <iostream>

#include "Game.h"

ConsoleInput map_user_input(char user_input)
{
    switch (user_input)
    {
        case 'a':
            {
                return ConsoleInput::LEFT;
            }
        case 'd':
            {
                return ConsoleInput::RIGHT;
            }
        case 'w':
            {
                return ConsoleInput::UP;
            }
        case 's':
            {
                return ConsoleInput::DOWN;
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

Position execute_move(Position player,
    ConsoleInput move)
{
    switch (move)
    {
        case ConsoleInput::LEFT:
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

                break;
            }
        case ConsoleInput::RIGHT:
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

                break;
            }
        case ConsoleInput::UP:
            {
                if (player.first > START.first)
                {
                    player.first--;

                    std::cout << "You moved upwards!" << std::endl;
                }
                else
                {
                    std::cout << "You bounced!" << std::endl;
                }

                break;
            }
        case ConsoleInput::DOWN:
            {
                if (player.first < GOAL.first)
                {
                    player.first++;

                    std::cout << "You moved downwards!" << std::endl;
                }
                else
                {
                    std::cout << "You bounced!" << std::endl;
                }

                break;
            }
        case ConsoleInput::INVALID:
        default:
            {
                std::cout << "Unrecognized move!" << std::endl;

                break;
            }
    }

    return player;
}

bool is_finished(Position player)
{
    bool finished = false;

    if (GOAL == player)
    {
        finished = true;

        std::cout << "You won the game!" << std::endl;
    }

    return finished;
}

void game()
{
    Position player = { 0, 0 };
    char user_input;
    ConsoleInput move;
    bool finished = false;

    while (!finished)
    {
        print_game_state(player);
        std::cin >> user_input;
        move = map_user_input(user_input);
        system("clear");
        player = execute_move(player, move);
        finished = is_finished(player);
    }
}
