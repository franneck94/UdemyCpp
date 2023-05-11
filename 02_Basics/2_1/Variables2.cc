#include <iostream>

int main()
{
    float my_value1 = 10.0;
    float my_value2 = 5.0;

    float my_result1 = my_value1 + my_value2;
    std::cout << "addition: " << my_result1 << std::endl;

    float my_result2 = my_value1 - my_value2;
    std::cout << "subtraction: " << my_result2 << std::endl;

    float my_result3 = my_value1 * my_value2;
    std::cout << "multiplication: " << my_result3 << std::endl;

    float my_result4 = my_value1 / my_value2;
    std::cout << "division: " << my_result4 << std::endl;

    return 0;
}
