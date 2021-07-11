#include <iostream>

// 1.) User-Input: integer number
// 2.) Compute if the number is a prime number
// 3.) Print out the result

// Prime Number: Only divisble by itself and 1 with a remainder of 0

int main()
{
    bool is_prime = true;

    int number;
    std::cout << "Please enter the number: ";
    std::cin >> number;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            is_prime = false;
        }
    }

    if (is_prime == true)
    {
        std::cout << "Is a prime number!" << std::endl;
    }
    else
    {
        std::cout << "Is not a prime number!" << std::endl;
    }

    return 0;
}
