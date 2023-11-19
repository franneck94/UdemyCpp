#include <cstdint>
#include <iostream>
#include <vector>

#include "Game.h"

namespace
{
constexpr static auto NUM_OBSTACLES = 3U;
constexpr static auto LEN_X = 5U;
constexpr static auto LEN_Y = 5U;
constexpr static auto START = Coordinate{.x = 0, .y = 0};
constexpr static auto GOAL = Coordinate{.x = LEN_X - 1, .y = LEN_Y - 1};
}; // namespace

bool is_finished(const Coordinate &player)
{
    return player.x == GOAL.x && player.y == GOAL.y;
}

void print_game_state(const Coordinate &player,
                      const std::vector<Coordinate> &obstacles)
{
    auto game_state = std::vector<std::string>(LEN_X, std::string(LEN_Y, '.'));
    for (std::uint32_t i = 0; i < LEN_X; i++)
    {
        for (std::uint32_t j = 0; j < LEN_Y; j++)
        {
            if (i == player.x && j == player.y)
            {
                game_state[i][j] = 'P';
            }
            else if ((i == GOAL.x && j == GOAL.y) ||
                     (i == START.x && j == START.y))
            {
                game_state[i][j] = '|';
            }
        }
    }
    for (const auto &obs : obstacles)
    {
        game_state[obs.x][obs.y] = 'X';
    }

    for (const auto &row : game_state)
    {
        std::cout << row << '\n';
    }
}

bool has_obstacle(const Coordinate &coord,
                  const std::vector<Coordinate> &obstacles)
{
    for (const auto &obs : obstacles)
    {
        if (coord.x == obs.x && coord.y == obs.y)
            return true;
    }

    return false;
}

void execute_move(Coordinate &player,
                  const ConsoleInput move,
                  const std::vector<Coordinate> &obstacles)
{
    switch (move)
    {
    case ConsoleInput::LEFT:
    {
        if (player.y > 0 &&
            !has_obstacle(Coordinate{player.x, player.y - 1U}, obstacles))
            player.y--;
        break;
    }
    case ConsoleInput::RIGHT:
    {
        if (player.y < LEN_X - 1 &&
            !has_obstacle(Coordinate{player.x, player.y + 1U}, obstacles))
            player.y++;
        break;
    }
    case ConsoleInput::UP:
    {
        if (player.x > 0 &&
            !has_obstacle(Coordinate{player.x - 1U, player.y}, obstacles))
            player.x--;
        break;
    }
    case ConsoleInput::DOWN:
    {
        if (player.x < LEN_Y - 1 &&
            !has_obstacle(Coordinate{player.x + 1U, player.y}, obstacles))
            player.x++;
        break;
    }
    case ConsoleInput::INVALID:
    default:
    {
        std::cout << "Unrecognized move!\n";
        break;
    }
    }
}

void game()
{
    const auto obstacles = std::vector<Coordinate>{
        Coordinate{.x = 1, .y = 1},
        Coordinate{.x = 2, .y = 2},
        Coordinate{.x = 3, .y = 3},
    };
    auto player = START;
    auto move = ConsoleInput::INVALID;
    auto move_char = ' ';

    while (true)
    {
        if (is_finished(player))
        {
            break;
        }

        print_game_state(player, obstacles);
        std::cin >> move_char;
        move = static_cast<ConsoleInput>(move_char);
        execute_move(player, move, obstacles);
    }
}
