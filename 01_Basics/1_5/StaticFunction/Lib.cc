#include <iostream>

#include "Lib.h"

static int data1[10]{};

void function()
{
    helper();
}

static void helper()
{
    static int data2[10]{};
    int data3[10]{};

    std::cout << data1[0] << std::endl;
    std::cout << data2[0] << std::endl;
    std::cout << data3[0] << std::endl;

    data1[0] = -1;
    data2[0] = -1;
    data3[0] = -1;
}
