#include <iostream>
#include <stdlib.h>

#include "Game.h"
#include "Helper.h"

#define LEN_X 5
#define LEN_Y 5

/*********************************/
/*         GAME FUNCTIONS        */
/*********************************/

void game()
{
    Position player(0, 0);
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
        game_state = update_game_state(player, goal, obstacles);
        print_game_state(game_state);
        std::cin >> move;
        system("CLS");
        player = execute_move(player, move, obstacles, finished);
        move_obstacles(obstacles, goal, player);
        if (is_finished(player, goal))
            finished = true;
    }
}

void print_game_state(GameState &game_state)
{
    for (int i = 0; i < LEN_X; ++i)
    {
        for (int j = 0; j < LEN_Y; ++j)
        {
            std::cout << game_state[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

GameState update_game_state(Position &player, Position &goal, Obstacles &obstacles)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    for (auto &obs : obstacles)
    {
        game_state[obs.first][obs.second] = 'X';
    }

    game_state[player.first][player.second] = 'P';
    game_state[goal.first][goal.second] = 'O';

    return game_state;
}

Position execute_move(Position &player, ConsoleInput &move, Obstacles &obstacles, bool &finished)
{
    Position new_pos;

    if (move == LEFT)
    {
        new_pos = Position(player.first, player.second - 1);
    }
    else if (move == RIGHT)
    {
        new_pos = Position(player.first, player.second + 1);
    }
    else if (move == UP)
    {
        new_pos = Position(player.first - 1, player.second);
    }
    else if (move == DOWN)
    {
        new_pos = Position(player.first + 1, player.second);
    }
    else
    {
        std::cout << "Unrecognized move!" << std::endl;
    }

    if (is_killed(new_pos, obstacles))
    {
        std::cout << "You died!" << std::endl;
        finished = true;
        return player;
    }
    else if (is_inbounds(new_pos))
    {
        std::cout << "You moved!" << std::endl;
        return new_pos;
    }
    else
    {
        std::cout << "You bounced!" << std::endl;
        return player;
    }

    return player;
}

void move_obstacles(Obstacles &obstacles, Position &goal, Position &player)
{
    std::vector<char> move_set = { LEFT, UP, RIGHT, DOWN };

    for (auto &obs : obstacles)
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

        if (is_inbounds(new_pos) && !is_occupied(new_pos, obstacles) && new_pos != player && new_pos != goal)
        {
            obs = new_pos;
        }
    }
}

/*********************************/
/*      GAME LOGIC FUNCTIONS     */
/*********************************/

bool is_killed(Position &pos, Obstacles &obstacles)
{
    for (auto &obs : obstacles)
    {
        if (pos == obs)
            return true;
    }

    return false;
}

bool is_inbounds(Position &new_pos)
{
    if (new_pos.first >= 0 && new_pos.second >= 0 && new_pos.first < LEN_X && new_pos.second < LEN_Y)
        return true;
    else
        return false;
}

bool is_finished(Position &player, Position &goal)
{
    if (player == goal)
    {
        std::cout << "You won the game!" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool is_occupied(Position &obs_pos, Obstacles &obstacles)
{
    for (auto &obs : obstacles)
    {
        if (obs_pos == obs)
            return true;
    }

    return false;
}