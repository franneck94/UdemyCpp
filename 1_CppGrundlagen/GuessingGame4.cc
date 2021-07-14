#include <iostream>

int main()
{
    int number_games;

    std::cout << "Welcome to the Guessing-Game!" << std::endl;
    std::cout << "How many trys will you buy? ";
    std::cin >> number_games;

    for (int i = 0; i < number_games; i++)
    {
        int number;
        std::cout << "Please enter your number: ";
        std::cin >> number;

        if (number >= 0 && number <= 10)
        {
            if (number == 4)
            {
                std::cout << "You won!" << std::endl;
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
