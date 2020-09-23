#include <iostream>

int main()
{
    // Lest eine positive ganze Zahl vom User ein.
    // Ueberprueft, ob diese Zahl eine Primzahl ist.
    // Primzahlen: Nur durch sich selbst und 1 (ohne Rest) teilbar.
    bool is_prime = true;
    unsigned int number;

    std::cout << "Please enter a number: ";
    std::cin >> number;

    // 9
    // [2, 3, 4, 5, 6, 7, 8]
    for (int i = 3; i < number; i++)
    {
        if (number % i == 0)
        {
            is_prime = false;
            break;
        }
    }

    if (is_prime == false)
        std::cout << "The number " << number << " is not a prime number!" << std::endl;
    else
        std::cout << "The number " << number << " is a prime number!" << std::endl;

    return 0;
}