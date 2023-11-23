#include <cstdint>
#include <iostream>

int main()
{
    char LEFT = 'a';
    char RIGHT = 'd';

    char input;
    std::cin >> input;

    if (LEFT == input)
    {
        std::cout << "The player moved to the left!\n";
    }
    else if (RIGHT == input)
    {
        std::cout << "The player moved to the right!\n";
    }
    else
    {
        std::cout << "Unrecoginzed move!\n";
    }

    return 0;
}
