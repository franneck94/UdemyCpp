#include <iostream>
#include <stdlib.h>
#include <random>

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
	GameState &game_state)
{
	for (int i = 0; i < LEN_X; ++i)
	{
		for (int j = 0; j < LEN_Y; ++j)
		{
			cout << game_state[i][j] << " ";
		}

		cout << endl;
	}
}

GameState update_game_state(
	Position &player_pos,
	Position &goal,
	Position &start,
	Obstacles &obstacles)
{
	GameState game_state(LEN_X, std::string(LEN_Y, '.'));

	for (auto &obs : obstacles)
	{
		game_state[obs.first][obs.second] = 'x';
	}

	game_state[start.first][start.second] = '|';
	game_state[player_pos.first][player_pos.second] = 'P';
	game_state[goal.first][goal.second] = '|';

	return game_state;
}

Position execute_move(
	Position &player_pos, 
	ConsoleInput &move,
	Obstacles &obstacles,
	bool &finished)
{
	Position new_pos;

	// Fuehre den eingegebenen move aus
	if (move == LEFT)
	{
		new_pos = Position(player_pos.first, player_pos.second - 1);
	}
	else if (move == RIGHT)
	{
		new_pos = Position(player_pos.first, player_pos.second + 1);
	}
	else if (move == UP)
	{
		new_pos = Position(player_pos.first - 1, player_pos.second);
	}
	else if (move == DOWN)
	{
		new_pos = Position(player_pos.first + 1, player_pos.second);
	}
	else
	{
		cout << "Unrecognized move!" << endl;
	}

	// Run into obstacle?
	if (is_dead(new_pos, obstacles))
	{
		cout << "You died!" << endl;
		finished = true;
		return player_pos;
	}
	// Valid move?
	else if (is_valid_move(new_pos))
	{
		cout << "You moved!" << endl;
		return new_pos;
	}
	// Bounced
	else
	{
		cout << "You bounced!" << endl;
		return player_pos;
	}

	return player_pos;
}

bool is_dead(
	Position &pos,
	Obstacles &obstacles)
{
	for (auto &obs : obstacles)
	{
		if (pos == obs)
			return true;
	}

	return false;
}

bool is_valid_move(
	Position &new_pos)
{
	if (new_pos.first >= 0 && new_pos.second >= 0 &&
		new_pos.first < LEN_X && new_pos.second < LEN_Y)
		return true;
	else
		return false;
}

bool is_finished(
	Position &player_pos,
	Position &goal)
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

UInt random_uint(
	const UInt &lbound,
	const UInt &ubound)
{
	std::random_device gen;
	std::uniform_int_distribution<UInt> dist(lbound, ubound);
	return dist(gen);
}

Position random_position(
	const UInt &lbound1,
	const UInt &ubound1,
	const UInt &lbound2,
	const UInt &ubound2)
{
	Position pos(random_uint(lbound1, ubound1), random_uint(lbound2, ubound2));
	return pos;
}

void game()
{
	// LEN_X = 10
	// Wir haben 10 Spielfelder insgesamt
	// Pos 0: Start, Pos 9: Ziel
	Position player_pos(0, 0);
	Position start(0, 0);
	Position goal = random_position(2, LEN_X - 1, 2, LEN_Y - 1);

	UInt num_obstacles = 3;
	Obstacles obstacles(num_obstacles, Position(0, 0));
	for (auto &obs : obstacles)
	{
		obs = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
	}

	GameState game_state;
	ConsoleInput move;
	bool finished = false;

	while (!finished)
	{
		game_state = update_game_state(player_pos, goal, start, obstacles);
		print_game_state(game_state);
		cin >> move;
		system("CLS");
		player_pos = execute_move(player_pos, move, obstacles, finished);	
		if (is_finished(player_pos, goal))
			finished = true;
	}
}