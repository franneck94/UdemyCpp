#include <iostream>
#include <random>

#include "Game.h"

uint32_t random_uint(const uint32_t lower, const uint32_t upper)
{
    std::random_device gen;
    std::uniform_int_distribution<uint32_t> dist(lower, upper);

    return dist(gen);
}

Position random_position(const uint32_t lower_x,
                         const uint32_t upper_x,
                         const uint32_t lower_y,
                         const uint32_t upper_y)
{
    return Position{random_uint(lower_x, upper_x), random_uint(lower_y, upper_y)};
}

ConsoleInput map_user_input(const char user_input)
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

void print_game_state(const Position &player, const Obstacles &obstacles)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    game_state[START.first][START.second] = '|';
    game_state[GOAL.first][GOAL.second] = '|';
    game_state[player.first][player.second] = 'P';

    for (const auto &obs : obstacles)
    {
        game_state[obs.first][obs.second] = 'X';
    }

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        for (unsigned int j = 0; j < LEN_Y; j++)
        {
            std::cout << game_state[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void execute_move(Position &player, const ConsoleInput move)
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

bool is_dead(const Position &player, const Obstacles &obstacles)
{
    for (const auto &obs : obstacles)
    {
        if (player == obs)
            return true;
    }

    return false;
}

bool is_finished(const Position &player)
{
    return player == GOAL;
}

void game()
{
    Position player = std::make_pair(0, 0);
    char user_input = 0;

    Obstacles obstacles(NUM_OBSTACLES, Position{0, 0});
    for (auto &obs : obstacles)
    {
        obs = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
    }

    while (true)
    {
        if (is_finished(player) || is_dead(player, obstacles))
        {
            break;
        }

        print_game_state(player, obstacles);
        std::cin >> user_input;
        ConsoleInput console_input = map_user_input(user_input);
        execute_move(player, console_input);
    }
}
