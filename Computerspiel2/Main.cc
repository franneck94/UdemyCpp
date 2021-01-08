#include <iostream>
#include <stdlib.h>

#include "Game.h"

int main()
{
    bool repeat = true;

    while (repeat)
    {
        game();

        std::cout << "Play again? (0=N, 1=Y)" << std::endl;
        std::cin >> repeat;

        system("clear");
    }

    return 0;
}
