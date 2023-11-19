#include <cstdint>
#include <iostream>
#include <random>
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

std::int32_t random_int(const std::int32_t lower, const std::int32_t upper)
{
    static auto gen = std::random_device{};
    static auto dist =
        std::uniform_int_distribution<std::int32_t>(lower, upper);

    return dist(gen);
}

std::uint32_t random_uint(const std::uint32_t lower, const std::uint32_t upper)
{
    static auto gen = std::random_device{};
    static auto dist =
        std::uniform_int_distribution<std::uint32_t>(lower, upper);

    return dist(gen);
}

Coordinate random_coord(const std::uint32_t lower_x,
                        const std::uint32_t upper_x,
                        const std::uint32_t lower_y,
                        const std::uint32_t upper_y)
{
    return Coordinate{.x = random_uint(lower_x, upper_x),
                      .y = random_uint(lower_y, upper_y)};
}

void move_obstacles(std::vector<Coordinate> &obstacles)
{
    for (auto &obs : obstacles)
    {
        const auto move_x = random_int(-1, 1);
        const auto move_y = random_int(-1, 1);

        const auto move_coord = Coordinate{obs.x + move_x, obs.y + move_y};
        if (move_coord.x < LEN_X && move_coord.y < LEN_Y)
        {
            obs.x += move_x;
            obs.y += move_y;
        }
    }
}

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
    auto obstacles = std::vector<Coordinate>(3, Coordinate{});
    for (auto &obs : obstacles)
    {
        obs = random_coord(1, LEN_X - 1, 1, LEN_Y - 1);
    }

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
        move_obstacles(obstacles);
    }
}
