#pragma once

#include <string>
#include <utility>
#include <vector>

using Position = std::pair<unsigned int, unsigned int>;
using GameState = std::vector<std::string>;
using Obstacles = std::vector<Position>;

constexpr unsigned int NUM_OBSTACLES = 3;
constexpr unsigned int LEN_X = 5;
constexpr unsigned int LEN_Y = 5;
constexpr Position START = { 0, 0 };

enum class ConsoleInput : int
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    INVALID = 4
};

class Game
{
public:
    Game();

    ConsoleInput map_user_input(char user_input);

    void update_game_state();

    void print_game_state();

    void move_player(ConsoleInput move);

    void move_obstacles();

    void generate_random_obstacles();

    bool is_dead();

    bool is_finished();

    unsigned int random_uint(const unsigned int lower,
        const unsigned int upper);

    Position random_position(const unsigned int lower_x,
        const unsigned int upper_x,
        const unsigned int lower_y,
        const unsigned int upper_y);

    void start_game();

private:
    Position m_player;
    Position m_goal;
    GameState m_game_state;
    Obstacles m_obstacles;
};
