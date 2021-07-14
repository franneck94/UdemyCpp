#include <iostream>

int main()
{
    bool has_won = false;
    std::cout << "Welcome to the Guessing-Game!" << std::endl;

    while (has_won == false)
    {
        int number;
        std::cout << "Please enter your number: ";
        std::cin >> number;

        if (number >= 0 && number <= 10)
        {
            if (number == 4)
            {
                std::cout << "You won!" << std::endl;
                has_won = true;
            }
            else if (number % 2 == 0)
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
            std::cout << "You must enter a number between [0, 10]."
                      << std::endl;
        }
    }

    return 0;
}
