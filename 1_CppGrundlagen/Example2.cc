#include <iostream>

// 1.) User-Input: radius of a circle
// 2.) Compute the perimeter and area of a circle.
// 3.) Print out the values to the console.
// u = 2 * PI * r
// A = PI * r^2

int main()
{
    const double PI = 3.14159;

    double radius;
    std::cout << "Please enter the radius: ";
    std::cin >> radius;

    double perimeter = 2 * PI * radius;
    double area = PI * radius * radius;

    std::cout << "The perimeter is: " << perimeter << std::endl;
    std::cout << "The area is: " << area << std::endl;

    return 0;
}
