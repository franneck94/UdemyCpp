#include <iostream>

// Multiplication *
// Addition +
// Subtraction -
// Division /

int main()
{
    double number1 = 10.0;
    double number2 = 2.0;
    double result = 0.0;

    result = number1 * number2;
    std::cout << "number1 * number2 = " << result << std::endl;

    result = number1 + number2;
    std::cout << "number1 + number2 = " << result << std::endl;

    result = number1 - number2;
    std::cout << "number1 - number2 = " << result << std::endl;

    result = number1 / number2;
    std::cout << "number1 / number2 = " << result << std::endl;

    return 0;
}
