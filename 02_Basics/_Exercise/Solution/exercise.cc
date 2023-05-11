#include <iostream>

#include "exercise.h"

void mod_cross_sum(int I, int J)
{
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            if (((i + j) % 2) == 1)
            {
                std::cout << "i: " << i << " , j: " << j << " := Odd!" << '\n';
            }
            else
            {
                std::cout << "i: " << i << " , j: " << j << " := Even!" << '\n';
            }
        }
    }
}
