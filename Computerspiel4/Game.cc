//#include <iostream>
//#include <stdlib.h>
//#include <random>
//
//#include "Game.hpp"
//
//#define LEN_X 5
//#define LEN_Y 5
//#define LEFT 'a'
//#define RIGHT 'd'
//#define UP 'w'
//#define DOWN 's'
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//void print_game_state(
//	GameState &game_state)
//{
//	for (int i = 0; i < LEN_X; ++i)
//	{
//		for (int j = 0; j < LEN_Y; ++j)
//		{
//			cout << game_state[i][j] << " ";
//		}
//
//		cout << endl;
//	}
//}
//
//GameState update_game_state(
//	Position &player_pos,
//	Position &goal,
//	Position &start)
//{
//	GameState game_state(LEN_X, std::string(LEN_Y, '.'));
//
//	game_state[start.first][start.second] = '|';
//	game_state[player_pos.first][player_pos.second] = 'P';
//	game_state[goal.first][goal.second] = '|';
//
//	return game_state;
//}
//
//Position execute_move(
//	Position &player_pos, 
//	ConsoleInput &move)
//{
//	// Fuehre den eingegebenen move aus
//	if (move == LEFT)
//	{
//		if (player_pos.second > 0)
//		{
//			player_pos.second--;
//			cout << "You moved left!" << endl;
//		}
//		else
//		{
//			cout << "You bounced!" << endl;
//		}
//	}
//	else if (move == RIGHT)
//	{
//		// player_pos <= 8
//		if (player_pos.second < LEN_Y - 1)
//		{
//			player_pos.second++;
//			cout << "You moved right!" << endl;
//		}
//		else
//		{
//			cout << "You bounced!" << endl;
//		}
//	}
//	else if (move == UP)
//	{
//		if (player_pos.first > 0)
//		{
//			player_pos.first--;
//			cout << "You moved up!" << endl;
//		}
//		else
//		{
//			cout << "You bounced!" << endl;
//		}
//	}
//	else if (move == DOWN)
//	{
//		if (player_pos.first < LEN_X - 1)
//		{
//			player_pos.first++;
//			cout << "You moved down!" << endl;
//		}
//		else
//		{
//			cout << "You bounced!" << endl;
//		}
//	}
//	else
//	{
//		cout << "Unrecognized move!" << endl;
//	}
//
//	return player_pos;
//}
//
//bool is_finished(
//	Position &player_pos,
//	Position &goal)
//{
//	// Ueberpreufe ob das Spiel gewonnen ist
//	if (player_pos == goal)
//	{
//		cout << "You won the game!" << endl;
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//UInt random_uint(
//	const UInt &lbound,
//	const UInt &ubound)
//{
//	std::random_device gen;
//	std::uniform_int_distribution<UInt> dist(lbound, ubound);
//	return dist(gen);
//}
//
//Position random_position(
//	const UInt &lbound1,
//	const UInt &ubound1,
//	const UInt &lbound2,
//	const UInt &ubound2)
//{
//	Position pos(random_uint(lbound1, ubound1), random_uint(lbound2, ubound2));
//	return pos;
//}
//
//void game()
//{
//	// LEN_X = 10
//	// Wir haben 10 Spielfelder insgesamt
//	// Pos 0: Start, Pos 9: Ziel
//	Position player_pos(0, 0);
//	Position start(0, 0);
//	Position goal(LEN_X-1, LEN_Y-1);
//
//	GameState game_state;
//	ConsoleInput move;
//	bool finished = false;
//
//	while (!finished)
//	{
//		game_state = update_game_state(player_pos, goal, start);
//		print_game_state(game_state);
//		cin >> move;
//		system("CLS");
//		player_pos = execute_move(player_pos, move);
//		finished = is_finished(player_pos, goal);
//	}
//}