#include <iostream>

// 1.) User-Input: number
// 2.) Compute the absolute value of the number
// 3.) Print out the absolute value

// x < 0: -x
// x >= 0: x

int main()
{
    double x = 0.0F; // Funktioniert auch für int, float, ...
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
