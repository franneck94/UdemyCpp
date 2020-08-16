//#pragma once
//
//#include <string>
//#include <vector>
//#include <utility>
//
//typedef unsigned int UInt;
//typedef char ConsoleInput;
//typedef std::pair<UInt, UInt> Position;
//typedef std::vector<std::string> GameState;
//typedef std::vector<Position> Obstacles;
//
//enum
//{
//	LEFT = 'a',
//	RIGHT = 'd',
//	UP = 'w',
//	DOWN = 's'
//};
//
///*********************************/
///*         GAME FUNCTIONS        */
///*********************************/
//
//void game();
//
//void print_game_state(
//	GameState &game_state);
//
//GameState update_game_state(
//	Position &player,
//	Position &goal,
//	Obstacles &obstacles);
//
//Position execute_move(
//	Position &player,
//	ConsoleInput &move,
//	Obstacles &obstacles,
//	bool &finished);
//
///*********************************/
///*      GAME LOGIC FUNCTIONS     */
///*********************************/
//
//bool is_killed(
//	Position &pos,
//	Obstacles &obstacles);
//
//bool is_valid_move(
//	Position &new_pos);
//
//bool is_finished(
//	Position &player,
//	Position &goal);