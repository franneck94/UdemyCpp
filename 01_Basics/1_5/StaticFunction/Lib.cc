#include <iostream>

#include "Lib.h"

void function()
{
    std::cout << "Function\n";

    helper();
}

static void helper()
{
    std::cout << "Internal Function\n";
}
