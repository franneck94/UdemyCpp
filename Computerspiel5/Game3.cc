#include <iostream>
#include <stdlib.h>

#include "Game3.h"
#include "Helper.h"

using std::cout;
using std::cin;
using std::endl;

/*********************************/
/*   CONSTRUCTOR / DESTRUCTOR    */
/*********************************/
Game::Game(const UInt &len_x, const UInt &len_y) :
	LEN_X(len_x), LEN_Y(len_y), m_num_obstacles(3)
{
	std::cout << "Created Game Instance - with GridSize: " << LEN_X << "," << LEN_Y << std::endl;
}

Game::~Game()
{
	std::cout << "Deleted Game Instance" << std::endl;
}

/*********************************/
/*         GAME FUNCTIONS        */
/*********************************/

void Game::start_game()
{
	m_player = Position(0, 0);
	m_goal = random_position(2, LEN_X - 1, 2, LEN_Y - 1);
	generate_random_obstacles();
	m_game_state = GameState();

	ConsoleInput move;
	bool finished = false;

	while (!finished)
	{
		update_game_state();
		print_game_state();
		cin >> move;
		system("CLS");
		move_player(move, finished);
		move_obstacles();
		if (is_finished())
			finished = true;
	}
}

void Game::update_game_state()
{
	m_game_state = GameState(LEN_X, std::string(LEN_Y, '.'));

	for (auto &obs : m_obstacles)
	{
		m_game_state[obs.first][obs.second] = 'X';
	}

	m_game_state[m_player.first][m_player.second] = 'P';
	m_game_state[m_goal.first][m_goal.second] = 'O';
}

void Game::print_game_state()
{
	for (int i = 0; i < LEN_X; ++i)
	{
		for (int j = 0; j < LEN_Y; ++j)
		{
			cout << m_game_state[i][j] << " ";
		}

		cout << endl;
	}
}

void Game::move_player(
	ConsoleInput &move,
	bool &finished)
{
	Position new_pos;

	if (move == LEFT)
	{
		new_pos = Position(m_player.first, m_player.second - 1);
	}
	else if (move == RIGHT)
	{
		new_pos = Position(m_player.first, m_player.second + 1);
	}
	else if (move == UP)
	{
		new_pos = Position(m_player.first - 1, m_player.second);
	}
	else if (move == DOWN)
	{
		new_pos = Position(m_player.first + 1, m_player.second);
	}
	else
	{
		cout << "Unrecognized move!" << endl;
	}

	if (is_killed(new_pos))
	{
		cout << "You died!" << endl;
		finished = true;
	}
	else if (is_inbounds(new_pos))
	{
		cout << "You moved!" << endl;
		m_player = new_pos;
	}
	else
	{
		cout << "You bounced!" << endl;
	}
}

void Game::move_obstacles()
{
	std::vector<char> move_set = { LEFT, UP, RIGHT, DOWN };

	for (auto &obs : m_obstacles)
	{
		UInt random_move_idx = random_uint(0, 3);
		char move = move_set[random_move_idx];
		Position new_pos;

		if (move == LEFT)
		{
			new_pos = Position(obs.first, obs.second - 1);
		}
		else if (move == RIGHT)
		{
			new_pos = Position(obs.first, obs.second + 1);
		}
		else if (move == UP)
		{
			new_pos = Position(obs.first - 1, obs.second);
		}
		else if (move == DOWN)
		{
			new_pos = Position(obs.first + 1, obs.second);
		}

		if (is_inbounds(new_pos) 
			&& !is_occupied(new_pos)
			&& new_pos != m_player
			&& new_pos != m_goal)
		{
			obs = new_pos;
		}
	}
}

void Game::generate_random_obstacles()
{
	m_obstacles = Obstacles(m_num_obstacles, Position(0, 0));

	for (auto &obs : m_obstacles)
	{
		Position pos; 

		do
		{
			pos = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
		} while (is_occupied(pos));

		obs = pos;
	}
}

/*********************************/
/*      GAME LOGIC FUNCTIONS     */
/*********************************/

bool Game::is_killed(
	Position &pos)
{
	for (auto &obs : m_obstacles)
	{
		if (pos == obs)
			return true;
	}

	return false;
}

bool Game::is_inbounds(
	Position &pos)
{
	if (pos.first >= 0 && pos.second >= 0 &&
		pos.first < LEN_X && pos.second < LEN_Y)
		return true;
	else
		return false;
}

bool Game::is_finished()
{
	if (m_player == m_goal)
	{
		cout << "You won the game!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::is_occupied(
	Position &pos)
{
	for (auto &obs : m_obstacles)
	{
		if (pos == obs)
			return true;
	}

	return false;
}