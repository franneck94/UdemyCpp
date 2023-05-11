#include <iostream>

// 1.) User-Input: side length of a square
// 2.) Compute the perimeter and area of a square.
// 3.) Print out the values to the console.

int main()
{
    double a = 0.0F;
    std::cout << "Please enter the value of a: ";
    std::cin >> a;

    double perimeter = 4.0 * a;
    double area = a * a;

    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}
