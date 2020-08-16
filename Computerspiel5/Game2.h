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
//void move_obstacles(
//	Obstacles &obstacles,
//	Position &goal,
//	Position &player);
//
///*********************************/
///*      GAME LOGIC FUNCTIONS     */
///*********************************/
//
//bool is_killed(
//	Position &pos,
//	Obstacles &obstacles);
//
//bool is_inbounds(
//	Position &new_pos);
//
//bool is_finished(
//	Position &player,
//	Position &goal);
//
//bool is_occupied(
//	Position &obs,
//	Obstacles &obstacles);