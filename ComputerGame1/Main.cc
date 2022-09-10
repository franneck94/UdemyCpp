#include <cstdint>
#include <iostream>

int main()
{
    char LEFT = 'a';
    char RIGHT = 'd';

    char move;
    std::cin >> move;

    if (LEFT == move)
    {
        std::cout << "The player moved to the left!\n";
    }
    else if (RIGHT == move)
    {
        std::cout << "The player moved to the right!\n";
    }
    else
    {
        std::cout << "Unrecognized move!\n";
    }

    return 0;
}
