#include <iostream>
#include <random>
#include <stdlib.h>


#include "Game.h"

#define LEN_X 5
#define LEN_Y 5
#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

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

GameState update_game_state(Position &player, Position &goal, Position &start, Obstacles &obstacles)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    for (auto &obs : obstacles)
    {
        game_state[obs.first][obs.second] = 'x';
    }

    game_state[start.first][start.second] = '|';
    game_state[player.first][player.second] = 'P';
    game_state[goal.first][goal.second] = '|';

    return game_state;
}

Position execute_move(Position &player, ConsoleInput &move, Obstacles &obstacles, bool &finished)
{
    Position new_pos;

    // Fuehre den eingegebenen move aus
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

    // Run into obstacle?
    if (is_dead(new_pos, obstacles))
    {
        std::cout << "You died!" << std::endl;
        finished = true;
        return player;
    }
    // Valid move?
    else if (is_valid_move(new_pos))
    {
        std::cout << "You moved!" << std::endl;
        return new_pos;
    }
    // Bounced
    else
    {
        std::cout << "You bounced!" << std::endl;
        return player;
    }

    return player;
}

bool is_dead(Position &pos, Obstacles &obstacles)
{
    for (auto &obs : obstacles)
    {
        if (pos == obs)
            return true;
    }

    return false;
}

bool is_valid_move(Position &new_pos)
{
    if (new_pos.first >= 0 && new_pos.second >= 0 && new_pos.first < LEN_X && new_pos.second < LEN_Y)
        return true;
    else
        return false;
}

bool is_finished(Position &player, Position &goal)
{
    // Ueberpreufe ob das Spiel gewonnen ist
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

UInt random_uint(const UInt &lbound, const UInt &ubound)
{
    std::random_device gen;
    std::uniform_int_distribution<UInt> dist(lbound, ubound);
    return dist(gen);
}

Position random_position(const UInt &lbound1, const UInt &ubound1, const UInt &lbound2, const UInt &ubound2)
{
    Position pos(random_uint(lbound1, ubound1), random_uint(lbound2, ubound2));
    return pos;
}

void game()
{
    // LEN_X = 10
    // Wir haben 10 Spielfelder insgesamt
    // Pos 0: Start, Pos 9: Ziel
    Position player(0, 0);
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
        game_state = update_game_state(player, goal, start, obstacles);
        print_game_state(game_state);
        std::cin >> move;
        system("clear");
        player = execute_move(player, move, obstacles, finished);
        if (is_finished(player, goal))
            finished = true;
    }
}