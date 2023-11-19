#include <cstdint>
#include <iostream>

int main()
{
    std::uint32_t max_number_of_attempts = 3;

    std::cout << "Welcome to my Guessing-Game!" << std::endl;
    std::cout << "You have to guess the correct number between [0, 10]!"
              << std::endl;

    for (std::uint32_t current_number_of_attempts = 0;
         current_number_of_attempts < max_number_of_attempts;
         current_number_of_attempts++)
    {
        std::uint32_t number = 0U;
        std::cout << "Please enter your guess: ";
        std::cin >> number;

        if ((number >= 0) && (number <= 10))
        {
            if (number == 4)
            {
                std::cout << "You won!" << std::endl;
            }
            else if (number == 2)
            {
                std::cout << "You won wooden spoon!" << std::endl;
            }
            else
            {
                std::cout << "You lost!" << std::endl;
            }
        }
        else
        {
            std::cout << "You entered an invalid number!" << std::endl;
        }
    }

    return 0;
}
