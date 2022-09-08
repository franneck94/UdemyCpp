#include <iostream>

// 1.) User-Input: integer number
// 2.) Compute the absolute value of an integer value
// 3.) Print out the absolute value

// x < 0: -x
// x >= 0: x

int main()
{
    double x = 0.0F;
    std::cout << "Please enter the value of x: ";
    std::cin >> x;

    double abs_x = x;

    if (x < 0)
    {
        abs_x = -1.0 * x;
    }

    std::cout << "Abs(" << x << ") = " << abs_x << std::endl;

    return 0;
}
