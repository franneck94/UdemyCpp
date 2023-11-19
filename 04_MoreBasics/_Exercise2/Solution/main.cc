#include <iostream>

#include "exercise.h"

int main()
{
    const auto p1 = PlayerData{.id = 0,
                               .x_pos = 10.0F,
                               .y_pos = 1.0F,
                               .health = 100,
                               .energy = 50,
                               .alliance = Alliance::ALLIED};
    const auto p2 = PlayerData{.id = 0,
                               .x_pos = 12.0F,
                               .y_pos = 6.0F,
                               .health = 80,
                               .energy = 50,
                               .alliance = Alliance::ENEMY};

    print_player_pos(p1);
    print_player_pos(p2);

    return 0;
}
