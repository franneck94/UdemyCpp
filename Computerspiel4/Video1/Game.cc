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

GameState update_game_state(Position &player, Position &goal, Position &start)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    game_state[start.first][start.second] = '|';
    game_state[player.first][player.second] = 'P';
    game_state[goal.first][goal.second] = '|';

    return game_state;
}

Position execute_move(Position &player, ConsoleInput &move)
{
    // Fuehre den eingegebenen move aus
    if (move == LEFT)
    {
        if (player.second > 0)
        {
            player.second--;
            std::cout << "You moved left!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (move == RIGHT)
    {
        // player <= 8
        if (player.second < LEN_Y - 1)
        {
            player.second++;
            std::cout << "You moved right!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (move == UP)
    {
        if (player.first > 0)
        {
            player.first--;
            std::cout << "You moved up!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (move == DOWN)
    {
        if (player.first < LEN_X - 1)
        {
            player.first++;
            std::cout << "You moved down!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else
    {
        std::cout << "Unrecognized move!" << std::endl;
    }

    return player;
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
    Position goal(LEN_X - 1, LEN_Y - 1);

    GameState game_state;
    ConsoleInput move;
    bool finished = false;

    while (!finished)
    {
        game_state = update_game_state(player, goal, start);
        print_game_state(game_state);
        std::cin >> move;
        system("clear");
        player = execute_move(player, move);
        finished = is_finished(player, goal);
    }
}