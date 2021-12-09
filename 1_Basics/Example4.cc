#include <iostream>

// 1.) User-Input: integer number (year)
// 2.) Compute if the year is a leap year
// 3.) Print out the absolute value

// Leap Year:
// 1.) divisible by 4
// 2.) if divisible by 100, then only a leap year if its divisible by 400

int main()
{
    int year;
    std::cout << "Please enter the year: ";
    std::cin >> year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                std::cout << "Is a leap year!" << std::endl;
            }
            else
            {
                std::cout << "Is not leap year!" << std::endl;
            }
        }
        else
        {
            std::cout << "Is a leap year!" << std::endl;
        }
    }
    else
    {
        std::cout << "Is not leap year!" << std::endl;
    }

    return 0;
}
