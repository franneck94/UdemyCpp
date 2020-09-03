#include <iostream>

#define LEN_X 10

int main()
{
    // LEN_X = 10
    // Wir haben 10 Spielfelder insgesamt
    // Pos 0: Start, Pos 9: Ziel
    unsigned int player_pos = 0;
    unsigned int start = 0;
    unsigned int goal = LEN_X - 1;

    for (int i = 0; i < LEN_X; i++)
    {
        if (i != player_pos && i != goal && i != start)
            std::cout << '.';
        else if (i == player_pos)
            std::cout << 'P';
        else if (i == goal || i == start)
            std::cout << '|';
    }

    return 0;
}