#include <iostream>
#include <string>

#include "Agent.h"

void polyFavouriteFood(Agent *&agent)
{
    agent->my_favourite_food();
}

int main()
{
    Agent a1;

    {
        std::string agent_name = "Tatze";
        Agent *agent1 = new Agent(agent_name);
        polyFavouriteFood(agent1);
        delete agent1;
    }

    std::cout << '\n';

    {
        std::string player_name = "Bello";
        Agent *player1 = new Player(player_name);
        polyFavouriteFood(player1);
        delete player1;
    }

    return 0;
}
