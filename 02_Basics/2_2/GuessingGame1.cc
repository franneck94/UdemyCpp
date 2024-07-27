#include <cstdint>
#include <iostream>

int main()
{
    // bool: true/false
    // [0, 10]

    std::uint32_t number;
    std::cout << "Please enter your guess: ";
    std::cin >> number;

    if ((number >= 0) && (number <= 10))
    {
        if (number == 4)
        {
            std::cout << "You won!\n";
        }
        else
        {
            std::cout << "You lost!\n";
        }
    }
    else
    {
        std::cout << "You entered an invalid number!\n";
    }

    return 0;
}
