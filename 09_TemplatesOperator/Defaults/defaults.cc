#include <iostream>

#include "defaults.h"

void my_function(int param1, int param2, int param3)
{
    std::cout << "Param 1: " << param1 << '\n';
    std::cout << "Param 2: " << param2 << '\n';
    std::cout << "Param 3: " << param3 << '\n';
}

int main()
{
    my_function(1, 2, 3);
    my_function(10, 20);

    return 0;
}
