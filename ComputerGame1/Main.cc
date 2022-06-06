#include <iostream>

int main()
{
    unsigned int LEN_X = 10;
    unsigned int START = 0;
    unsigned int GOAL = 9;

    char LEFT = 'a';
    char RIGHT = 'd';

    unsigned int player = 0;
    char move = 0;

    while (true)
    {
        if (player == GOAL)
        {
            break;
        }

        for (unsigned int i = START; i < LEN_X; i++)
        {
            if (i == player)
            {
                std::cout << 'P';
            }
            else if (i == GOAL || i == START)
            {
                std::cout << '|';
            }
            else
            {
                std::cout << '.';
            }
        }

        std::cin >> move;

        if (LEFT == move && player > 0)
        {
            player--;
        }
        else if (RIGHT == move && player < GOAL)
        {
            player++;
        }
        else
        {
            std::cout << "Unrecognized move!" << std::endl;
        }
    }

    return 0;
}
