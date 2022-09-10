#pragma once

#include <cstdint>

#define LEN_X 10
#define START 0
#define GOAL 9

#define LEFT 'a'
#define RIGHT 'd'

void print_game_state(std::uint32_t player);

std::uint32_t execute_move(std::uint32_t player, char move);

bool is_finished(std::uint32_t player);

void game();
