#include <iostream>

#include "exercise.h"

void print_player_pos(const PlayerData &player)
{
    std::cout << "Pos: (" << player.x_pos << ", " << player.y_pos << ")\n";
}
