#pragma once

#include <string>
#include <utility>
#include <vector>

typedef char ConsoleInput;
typedef std::pair<unsigned int, unsigned int> Position;
typedef std::vector<std::string> GameState;

void print_game_state(Position player);

Position execute_move(Position player, ConsoleInput move);

bool is_finished(Position player);

void game();
