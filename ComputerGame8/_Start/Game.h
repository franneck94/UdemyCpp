#pragma once

#include <cstdint>
#include <vector>

struct Coordinate
{
    std::uint32_t x;
    std::uint32_t y;
};

enum class ConsoleInput
{
    INVALID,
    LEFT = 'a',
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's',
};

class Game
{
private:
    constexpr static auto NUM_OBSTACLES = 3U;
    constexpr static auto LEN_X = 5U;
    constexpr static auto LEN_Y = 5U;
    constexpr static auto START = Coordinate{.x = 0, .y = 0};
    constexpr static auto GOAL = Coordinate{.x = LEN_X - 1, .y = LEN_Y - 1};

    Coordinate player = {.x = 0, .y = 0};
    std::vector<Coordinate> obstacles;

public:
    Game() : obstacles(std::vector<Coordinate>(NUM_OBSTACLES, Coordinate{})){};
    ~Game() = default;

    void game();

private:
    static std::int32_t random_int(const std::int32_t lower,
                                   const std::int32_t upper);

    static std::uint32_t random_uint(const std::uint32_t lower,
                                     const std::uint32_t upper);

    static Coordinate random_coord(const std::uint32_t lower_x,
                                   const std::uint32_t upper_x,
                                   const std::uint32_t lower_y,
                                   const std::uint32_t upper_y);

    bool has_obstacle(const Coordinate &coord);

    void move_obstacles();

    bool is_finished();

    void print_game_state();

    void execute_move(const ConsoleInput move);
};
