#include <string>
#include <vector>
#include <utility>

typedef unsigned int UInt;
typedef char ConsoleInput;
typedef std::pair<UInt, UInt> Position;
typedef std::vector<std::string> GameState;
typedef std::vector<Position> Obstacles;

void print_game_state(
	GameState &game_state);

GameState update_game_state(
	Position &player_pos,
	Position &goal,
	Position &start,
	Obstacles &obstacles);

Position execute_move(
	Position &player_pos,
	ConsoleInput &move,
	Obstacles &obstacles,
	bool &finished);

bool is_dead(
	Position &pos,
	Obstacles &obstacles);

bool is_valid_move(
	Position &new_pos);

bool is_finished(
	Position &player_pos,
	Position &goal);

UInt random_uint(
	const UInt &lbound,
	const UInt &ubound);

Position random_position(
	const UInt &lbound1,
	const UInt &ubound1,
	const UInt &lbound2,
	const UInt &ubound2);

void game();