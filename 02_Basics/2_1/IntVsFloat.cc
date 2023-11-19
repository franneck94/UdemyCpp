#include <iostream>

int main()
{
    int my_value1 = 10;
    int my_value2 = 3;

    int my_result1 = my_value1 + my_value2;
    std::cout << "addition: " << my_result1 << std::endl;

    int my_result2 = my_value1 - my_value2;
    std::cout << "subtraction: " << my_result2 << std::endl;

    int my_result3 = my_value1 * my_value2;
    std::cout << "multiplication: " << my_result3 << std::endl;

    int my_result4 = my_value1 / my_value2;
    std::cout << "division: " << my_result4 << std::endl;

    return 0;
}
