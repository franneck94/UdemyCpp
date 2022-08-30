#include <iostream>
#include <string>

#include "Agent.h"

int main()
{
    {
        Agent agent1("A1", 0, 100, 25);
    }

    std::cout << '\n';

    {
        Player player1("P1", 1, 250, 55);
    }

    std::cout << '\n';

    {
        NPC npc1("N1", 2, 235, 41);
    }

    return 0;
}
