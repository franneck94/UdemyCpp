#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

constexpr uint32_t LEN_X = 5;
constexpr uint32_t LEN_Y = 5;

enum class ConsoleInput
{
    INVALID,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

using Position = std::pair<uint32_t, uint32_t>;
using GameState = std::vector<std::string>;

constexpr Position START = std::make_pair(0U, 0U);
constexpr Position GOAL = std::make_pair(4U, 4U);

ConsoleInput map_user_input(char user_input);

void print_game_state(Position player);

void execute_move(Position &player, ConsoleInput move);

bool is_finished(Position player);

void game();
