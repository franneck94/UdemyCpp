#include <iostream>
#include <stdlib.h>

#include "Game2.hpp"

#define LEN_X 5
#define LEN_Y 5
#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

using std::cout;
using std::cin;
using std::endl;

void print_game_state(
	Position player_pos,
	Position goal,
	Position start)
{
	GameState game_state(LEN_X, std::string(LEN_Y, '.'));

	game_state[start.first][start.second] = '|';
	game_state[player_pos.first][player_pos.second] = 'P';
	game_state[goal.first][goal.second] = '|';

	for (int i = 0; i < LEN_X; ++i)
	{
		for (int j = 0; j < LEN_Y; ++j)
		{
			cout << game_state[i][j] << " ";
		}

		cout << endl;
	}
}

Position execute_move(
	Position player_pos, 
	ConsoleInput move)
{
	// Fuehre den eingegebenen move aus
	if (move == LEFT)
	{
		if (player_pos.second > 0)
		{
			player_pos.second--;
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
		if (player_pos.second < LEN_Y - 1)
		{
			player_pos.second++;
			cout << "You moved right!" << endl;
		}
		else
		{
			cout << "You bounced!" << endl;
		}
	}
	else if (move == UP)
	{
		if (player_pos.first > 0)
		{
			player_pos.first--;
			cout << "You moved up!" << endl;
		}
		else
		{
			cout << "You bounced!" << endl;
		}
	}
	else if (move == DOWN)
	{
		if (player_pos.first < LEN_X - 1)
		{
			player_pos.first++;
			cout << "You moved down!" << endl;
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
	Position player_pos,
	Position goal)
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
	Position player_pos(0, 0);
	Position start(0, 0);
	Position goal(LEN_X-1, LEN_Y-1);

	ConsoleInput move;
	bool finished = false;

	while (!finished)
	{
		print_game_state(player_pos, goal, start);
		cin >> move;
		system("CLS");
		player_pos = execute_move(player_pos, move);
		finished = is_finished(player_pos, goal);
	}
}