#include <iostream>
#include <stdlib.h>

#include "Game.hpp"

#define LEN_X 10
#define LEFT 'a'
#define RIGHT 'd'

using std::cin;
using std::cout;
using std::endl;

void print_game_state(
	unsigned int player_pos,
	unsigned int goal,
	unsigned int start)
{
	char game_state[LEN_X];

	for (int i = 0; i < LEN_X; i++)
	{
		game_state[i] = '.';
	}

	game_state[start] = '|';
	game_state[player_pos] = 'P';
	game_state[goal] = '|';

	for (int i = 0; i < LEN_X; i++)
	{
		cout << game_state[i] << " ";
	}
	cout << endl;
}

unsigned int execute_move(
	unsigned int player_pos,
	char move)
{
	// Fuehre den eingegebenen move aus
	if (move == LEFT)
	{
		if (player_pos > 0)
		{
			player_pos--;
			cout << "You moved left!" << endl;
		}
		else
		{
			cout << "You bounced!" << endl;
		}
	}
	else if (move == RIGHT)
	{
		// player_pos <= 8
		if (player_pos < LEN_X - 1)
		{
			player_pos++;
			cout << "You moved right!" << endl;
		}
		else
		{
			cout << "You bounced!" << endl;
		}
	}
	else
	{
		cout << "Unrecognized move!" << endl;
	}

	return player_pos;
}

bool is_finished(
	unsigned int player_pos,
	unsigned int goal)
{
	// Ueberpreufe ob das Spiel gewonnen ist
	if (player_pos == goal)
	{
		cout << "You won the game!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void game()
{
	// LEN_X = 10
	// Wir haben 10 Spielfelder insgesamt
	// Pos 0: Start, Pos 9: Ziel
	unsigned int player_pos = 0;
	unsigned int start = 0;
	unsigned int goal = LEN_X - 1;

	char move;
	bool finished = false;

	while (!finished)
	{
		print_game_state(player_pos, goal, start);
		cin >> move;
		system("clear");
		player_pos = execute_move(player_pos, move);
		finished = is_finished(player_pos, goal);
	}
}