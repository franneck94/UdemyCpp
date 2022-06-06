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
using Obstacles = std::vector<Position>;

constexpr Position START = std::make_pair(0U, 0U);
constexpr Position GOAL = std::make_pair(4U, 4U);
constexpr uint32_t NUM_OBSTACLES = 3U;

uint32_t random_uint(const uint32_t lower, const uint32_t upper);

Position random_position(const uint32_t lower_x,
                         const uint32_t upper_x,
                         const uint32_t lower_y,
                         const uint32_t upper_y);

ConsoleInput map_user_input(const char user_input);

void print_game_state(const Position &player, const Obstacles &obstacles);

void execute_move(Position &player, const ConsoleInput move);

bool is_dead(const Position &player, const Obstacles &obstacles);

bool is_finished(const Position &player);

void game();
