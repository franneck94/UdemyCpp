#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

constexpr static auto LEN_X = std::uint32_t{5};
constexpr static auto LEN_Y = std::uint32_t{5};

enum class ConsoleInput
{
    INVALID,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

using Position = std::pair<std::uint32_t, std::uint32_t>;
using GameState = std::vector<std::string>;

constexpr static Position START = std::make_pair(0U, 0U);
constexpr static Position GOAL = std::make_pair(4U, 4U);

ConsoleInput map_user_input(const char user_input);

void print_game_state(const Position player);

void execute_move(Position &player, const ConsoleInput move);

bool is_finished(const Position player);

void game();
