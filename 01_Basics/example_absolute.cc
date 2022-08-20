#include <iostream>

// 1.) User-Input: integer number
// 2.) Compute the absolute value of an integer value
// 3.) Print out the absolute value

// x < 0: -x
// x >= 0: x

int main()
{
    int value;
    std::cout << "Please enter the value: ";
    std::cin >> value;

    double absolute;

    if (value < 0)
    {
        absolute = (-1) * value;
    }
    else
    {
        absolute = value;
    }

    std::cout << "The absolute value is: " << absolute << std::endl;

    return 0;
}
