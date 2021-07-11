#include <iostream>

int main()
{
    int number;
    std::cout << "Please enter your number: ";
    std::cin >> number;

    if (number >= 0 && number <= 10)
    {
        std::cout << "TRUE";
    }
    else
    {
        std::cout << "FALSE";
    }

    return 0;
}
