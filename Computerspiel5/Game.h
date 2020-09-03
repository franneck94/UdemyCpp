#pragma once

#include <string>
#include <vector>
#include <utility>

typedef unsigned int UInt;
typedef char ConsoleInput;
typedef std::pair<UInt, UInt> Position;
typedef std::vector<std::string> GameState;
typedef std::vector<Position> Obstacles;

enum
{
	LEFT = 'a',
	RIGHT = 'd',
	UP = 'w',
	DOWN = 's'
};

class Game
{
public:
	/*********************************/
	/*   CONSTRUCTOR / DESTRUCTOR    */
	/*********************************/
	Game(const UInt &len_x, const UInt &len_y);
	~Game();

	/*********************************/
	/*         GAME FUNCTIONS        */
	/*********************************/

	void start_game();

	void update_game_state();

	void print_game_state();

	void move_player(
		ConsoleInput &move,
		bool &finished);

	void move_obstacles();

	void generate_random_obstacles();

	/*********************************/
	/*      GAME LOGIC FUNCTIONS     */
	/*********************************/

	bool is_killed(
		Position &pos);

	bool is_inbounds(
		Position &pos);

	bool is_finished();

	bool is_occupied(
		Position &pos);

private:
	GameState m_game_state;
	Position m_player;
	Position m_goal;
	UInt m_num_obstacles;
	Obstacles m_obstacles;
	const UInt LEN_X;
	const UInt LEN_Y;
};