#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

using Position = std::pair<std::uint32_t, std::uint32_t>;
using GameState = std::vector<std::string>;
using Obstacles = std::vector<Position>;

constexpr std::uint32_t NUM_OBSTACLES = 3;
constexpr std::uint32_t LEN_X = 5;
constexpr std::uint32_t LEN_Y = 5;
constexpr Position START = {0, 0};

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

    std::uint32_t random_uint(const std::uint32_t lower, const std::uint32_t upper);

    Position random_position(const std::uint32_t lower_x,
                             const std::uint32_t upper_x,
                             const std::uint32_t lower_y,
                             const std::uint32_t upper_y);

    void start_game();

private:
    Position m_player;
    Position m_goal;
    GameState m_game_state;
    Obstacles m_obstacles;
};
