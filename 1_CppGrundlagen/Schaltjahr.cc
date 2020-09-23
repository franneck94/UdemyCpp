#include <iostream>

int main()
{
    // All years which are perfectly divisible by 4 are leap years except for century years
    // (years ending with 00) which is leap year only it is perfectly divisible by 400.

    unsigned int year;
    std::cout << "Please enter the year: ";
    std::cin >> year;
    std::cout << "You entered the year: " << year << std::endl;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                std::cout << "The year: " << year << " is a leap year!" << std::endl;
            }
            else
            {
                std::cout << "The year: " << year << " is not a leap year!" << std::endl;
            }
        }
        else
        {
            std::cout << "The year: " << year << " is a leap year!" << std::endl;
        }
    }
    else
    {
        std::cout << "The year: " << year << " is not a leap year!" << std::endl;
    }

    return 0;
}