#include <string>
#include <utility>
#include <vector>


typedef unsigned int UInt;
typedef char ConsoleInput;
typedef std::pair<UInt, UInt> Position;
typedef std::vector<std::string> GameState;

void print_game_state(Position player_pos, Position goal, Position start);

Position execute_move(Position player_pos, ConsoleInput move);

bool is_finished(Position player_pos, Position goal);

void game();