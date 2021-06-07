#include <iostream>
#include <random>

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

GameState update_game_state(const Position &player,
    const Obstacles &obstacles)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    game_state[START.first][START.second] = '|';
    game_state[GOAL.first][GOAL.second] = '|';
    game_state[player.first][player.second] = 'P';

    for (const auto &obs : obstacles)
    {
        game_state[obs.first][obs.second] = 'x';
    }

    return game_state;
}

void print_game_state(const GameState &game_state)
{
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

bool is_dead(const Position &player,
    const Obstacles &obstacles)
{
    for (const auto &obs : obstacles)
    {
        if (player == obs)
        {
            return true;
        }
    }

    return false;
}

bool is_finished(Position player)
{
    bool finished = false;

    if (GOAL == player)
    {
        finished = true;
    }

    return finished;
}

unsigned int random_uint(const unsigned int lower,
    const unsigned int upper)
{
    std::random_device gen;
    std::uniform_int_distribution<unsigned int> dist(lower, upper);

    return dist(gen);
}

Position random_position(const unsigned int lower_x,
    const unsigned int upper_x,
    const unsigned int lower_y,
    const unsigned int upper_y)
{
    Position pos(random_uint(lower_x, upper_x), random_uint(lower_y, upper_y));

    return pos;
}

void game()
{
    Position player = { 0, 0 };
    char user_input = 0;
    ConsoleInput move = ConsoleInput::INVALID;
    bool finished = false;

    unsigned int num_obstacles = 3;
    Obstacles obstacles(num_obstacles, Position(0, 0));
    GameState game_state;

    for (auto &obs : obstacles)
    {
        obs = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
    }

    while (!finished)
    {
        game_state = update_game_state(player, obstacles);
        print_game_state(game_state);
        std::cin >> user_input;
        move = map_user_input(user_input);
        system("clear");
        player = execute_move(player, move);

        if (is_dead(player, obstacles))
        {
            finished = true;

            std::cout << "You died!" << std::endl;
        }
        else if (is_finished(player))
        {
            finished = true;

            std::cout << "You won the game!" << std::endl;
        }
    }
}
