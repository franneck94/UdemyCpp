#include <iostream>

// ReturnType FunctionName (ParameterList)
bool is_even(int number)
{
    if (number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int number1 = 3;
    bool check1 = is_even(number1);
    std::cout << check1 << std::endl;

    int number2 = 4;
    bool check2 = is_even(number2);
    std::cout << check2 << std::endl;

    int number3 = 5;
    bool check3 = is_even(number3);
    std::cout << check3 << std::endl;

    return 0;
}
