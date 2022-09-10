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
using Obstacles = std::vector<Position>;

constexpr static Position START = std::make_pair(0U, 0U);
constexpr static Position GOAL = std::make_pair(4U, 4U);
constexpr static auto NUM_OBSTACLES = std::uint32_t{3U};

std::uint32_t random_uint(const std::uint32_t lower, const std::uint32_t upper);

Position random_position(const std::uint32_t lower_x,
                         const std::uint32_t upper_x,
                         const std::uint32_t lower_y,
                         const std::uint32_t upper_y);

ConsoleInput map_user_input(const char user_input);

void print_game_state(const Position &player, const Obstacles &obstacles);

void execute_move(Position &player, const ConsoleInput move);

bool is_dead(const Position &player, const Obstacles &obstacles);

bool is_finished(const Position &player);

void game();
