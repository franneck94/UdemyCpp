#include <iostream>

int main()
{
    int number = 12;

    bool check1 = number % 2 == 0;
    bool check2 = number < 10;
    // true <=> wahr <=> 1
    // false <=> falsch <=> 0

    if (check1 == true && check2 == true)
    {
        std::cout << "Case 1!" << std::endl;
    }
    else if (check1 == true || check2 == true)
    {
        std::cout << "Case 2!" << std::endl;
    }
    else
    {
        std::cout << "Else Case!" << std::endl;
    }

    return 0;
}
