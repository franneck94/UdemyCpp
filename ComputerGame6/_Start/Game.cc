#include <cstdint>
#include <iostream>

#include "Game.h"

namespace
{
constexpr static auto LEN_X = 5U;
constexpr static auto LEN_Y = 5U;
constexpr static auto START = Coordinate{.x = 0, .y = 0};
constexpr static auto GOAL = Coordinate{.x = LEN_X - 1, .y = LEN_Y - 1};
}; // namespace

bool is_finished(const Coordinate &player)
{
    return player.x == GOAL.x && player.y == GOAL.y;
}

void print_game_state(const Coordinate &player)
{
    for (std::uint32_t i = 0; i < LEN_X; i++)
    {
        for (std::uint32_t j = 0; j < LEN_Y; j++)
        {
            if (i == player.x && j == player.y)
            {
                std::cout << 'P';
            }
            else if ((i == GOAL.x && j == GOAL.y) ||
                     (i == START.x && j == START.y))
            {
                std::cout << '|';
            }
            else
            {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void execute_move(Coordinate &player, const ConsoleInput move)
{
    switch (move)
    {
    case ConsoleInput::LEFT:
    {
        if (player.y > 0)
            player.y--;
        break;
    }
    case ConsoleInput::RIGHT:
    {
        if (player.y < LEN_X - 1)
            player.y++;
        break;
    }
    case ConsoleInput::UP:
    {
        if (player.x > 0)
            player.x--;
        break;
    }
    case ConsoleInput::DOWN:
    {
        if (player.x < LEN_Y - 1)
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
    auto player = START;
    auto move = ConsoleInput::INVALID;
    auto move_char = ' ';

    while (true)
    {
        if (is_finished(player))
        {
            break;
        }

        print_game_state(player);
        std::cin >> move_char;
        move = static_cast<ConsoleInput>(move_char);
        execute_move(player, move);
    }
}
