#include <iostream>
#include <string>
#include <vector>

#include "Agent.h"

void printAllAgents(const std::vector<Agent *> &agents)
{
    for (const auto agent : agents)
    {
        agent->print_agent_data();
    }
}

int main()
{
    auto player1 = Player("P1", 1, 250, 55);
    auto npc1 = NPC("N1", 2, 235, 41);

    const auto agents = std::vector<Agent *>{&player1, &npc1};
    printAllAgents(agents);

    return 0;
}
