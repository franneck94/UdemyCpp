#include <iostream>
#include <stdlib.h>

#include "Game.h"

int main()
{
    bool repeat = true;
    Game game(10, 10);

    while (true)
    {
        game.start_game();

        std::cout << "Play again? (0=N, 1=Y)" << std::endl;
        std::cin >> repeat;

        if (repeat == 0)
            break;

        system("clear");
    }

    return 0;
}
