#pragma once

void print_game_state(unsigned int player);

unsigned int execute_move(unsigned int player, char move);

bool is_finished(unsigned int player);

void game();
