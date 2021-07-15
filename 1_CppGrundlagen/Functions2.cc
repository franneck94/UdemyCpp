#include <iostream>

// ReturnType FunctionsName(ParameterList - optional)
// {
//    // FunctionCode
// }

int user_input()
{
    int number;
    std::cout << "Please enter a number: ";
    std::cin >> number;

    return number;
}

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
    int my_number = user_input();
    std::cout << my_number << std::endl;
    bool check = is_even(my_number);
    std::cout << std::boolalpha << check << std::endl;

    return 0;
}
