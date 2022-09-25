#include <iostream>

// Game Rules:
// Number in [0, 10]
// Number == 4: Win
// Number == 2: Wooden Spoon
// Else: Lost

int main()
{
    int number = 0;
    std::cout << "Please enter your number [0, 10]: ";
    std::cin >> number;

    if (number >= 0 && number <= 10)
    {
        if (number == 4)
        {
            std::cout << "You won!" << std::endl;
        }
        else if (number == 2)
        {
            std::cout << "You won the wooden spoon!" << std::endl;
        }
        else
        {
            std::cout << "You lost!" << std::endl;
        }
    }
    else
    {
        std::cout << "You must enter a number between [0, 10]" << std::endl;
    }

    return 0;
}
