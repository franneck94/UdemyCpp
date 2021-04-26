#include <iostream>
#include <stdlib.h>

#include "Game.h"

int main()
{
    bool repeat = true;
    Game game;

    while (repeat)
    {
        game.start_game();

        std::cout << "Play again? (0=No, 1=Yes)" << std::endl;
        std::cin >> repeat;

        system("clear");
    }

    return 0;
}
