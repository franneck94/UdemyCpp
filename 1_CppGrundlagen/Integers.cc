#include <iostream>

int main()
{
    int number1 = 10;
    int number2 = 3;
    int result = 0;

    result = number1 * number2;
    std::cout << "number1 * number2 = " << result << std::endl;

    result = number1 + number2;
    std::cout << "number1 + number2 = " << result << std::endl;

    result = number1 - number2;
    std::cout << "number1 - number2 = " << result << std::endl;

    result = number1 / number2;
    std::cout << "number1 / number2 = " << result << std::endl;

    int number3 = 1;
    double number4 = 2.5f;
    int result2 = number3 * number4;
    std::cout << "number3 * number4 = " << result2 << std::endl;

    return 0;
}
