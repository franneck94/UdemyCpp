#pragma once

#include <cstdint>

constexpr static auto LEN_X = std::uint32_t{10U};
constexpr static auto START = std::uint32_t{0U};
constexpr static auto GOAL = std::uint32_t{9U};
constexpr static char LEFT = 'a';
constexpr static char RIGHT = 'd';

void print_game_state(const std::uint32_t player);

void execute_move(std::uint32_t &player, const char move);

bool is_finished(const std::uint32_t player);

void game();
