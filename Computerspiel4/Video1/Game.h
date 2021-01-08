#include <string>
#include <utility>
#include <vector>


typedef unsigned int UInt;
typedef char ConsoleInput;
typedef std::pair<UInt, UInt> Position;
typedef std::vector<std::string> GameState;
typedef std::vector<Position> Obstacles;

void print_game_state(GameState &game_state);

GameState update_game_state(Position &player, Position &goal, Position &start);

Position execute_move(Position &player, ConsoleInput &move);

bool is_finished(Position &player, Position &goal);

UInt random_uint(const UInt &lbound, const UInt &ubound);

Position random_position(const UInt &lbound1, const UInt &ubound1, const UInt &lbound2, const UInt &ubound2);

void game();