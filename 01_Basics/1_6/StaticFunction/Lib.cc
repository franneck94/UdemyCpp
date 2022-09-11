#include <iostream>

#include "Lib.h"

static void helper()
{
    std::cout << "Internal Function\n";
}

void function()
{
    std::cout << "Function\n";

    helper();
}
