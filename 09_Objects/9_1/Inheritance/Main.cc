#include <iostream>

#include "Agent.h"

int main()
{
    std::cout << "Line 7\n";
    {
        auto agent1 = Agent{"A1", 0U};
    }
    std::cout << "Line 11\n";
    {
        auto player1 = Player{"P1", 1U};
    }
    std::cout << "Line 15\n";
    {
        auto npc1 = NPC{"N1", 2U};
    }
    std::cout << "Line 19\n";

    return 0;
}
