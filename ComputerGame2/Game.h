#pragma once

#define LEN_X 10
#define START 0
#define GOAL 9

#define LEFT 'a'
#define RIGHT 'd'

void print_game_state(unsigned int player);

unsigned int execute_move(unsigned int player, char move);

bool is_finished(unsigned int player);

void game();
