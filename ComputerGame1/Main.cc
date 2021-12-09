#include <iostream>

#define LEN_X 10u
#define LEFT 'a'
#define RIGHT 'd'

int main()
{
    unsigned int player = 0;
    unsigned int start = 0;
    unsigned int goal = LEN_X - 1;

    char move = 0;

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        if (i != player && i != start && i != goal)
        {
            std::cout << '.';
        }
        else if (i == player)
        {
            std::cout << 'P';
        }
        else
        {
            std::cout << '|';
        }
    }

    std::cin >> move;

    if (LEFT == move)
    {
        player--;
    }
    else if (RIGHT == move)
    {
        player++;
    }
    else
    {
        std::cout << "Unrecognized move!" << std::endl;
    }

    return 0;
}
