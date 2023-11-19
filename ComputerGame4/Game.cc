#include <cstdint>
#include <iostream>

#include "Game.h"

namespace
{
constexpr std::uint32_t LEN_X = 10U;
constexpr std::uint32_t START = 0U;
constexpr std::uint32_t GOAL = 9U;
constexpr char LEFT = 'a';
constexpr char RIGHT = 'd';
}; // namespace

bool is_finished(const std::uint32_t player)
{
    return player == GOAL;
}

void print_game_state(const std::uint32_t player)
{
    for (std::uint32_t i = START; i < LEN_X; i++)
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

void execute_move(std::uint32_t &player, const char move)
{
    if (LEFT == move && player > 0)
    {
        player--;
    }
    else if (RIGHT == move && player < (LEN_X - 1))
    {
        player++;
    }
    else
    {
        std::cout << "Unrecognized move!\n";
    }
}

void game()
{
    std::uint32_t player = START;
    char move;

    while (true)
    {
        if (is_finished(player))
        {
            break;
        }

        print_game_state(player);
        std::cin >> move;
        execute_move(player, move);
    }
}
