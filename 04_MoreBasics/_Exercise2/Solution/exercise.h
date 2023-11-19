#pragma once

// Exercise 1
enum class Alliance
{
    ALLIED,
    ENEMY,
};

struct PlayerData
{
    std::uint32_t id;
    float x_pos;
    float y_pos;
    std::uint32_t health;
    std::uint32_t energy;
    Alliance alliance;
};

// Exercise2
void print_player_pos(const PlayerData &player);
