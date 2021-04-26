// Hier die benötigten Includes und using Befehle
#include <iostream>

#include "exercise.h"

// Hier die Definition der Funktion
void mod_cross_sum(int I, int J)
{
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            // Ungerader Fall
            if ((i + j) % 2)
            {
                std::cout << "i: " << i << " , j: " << j << " := Ungerade!" << std::endl;
            }
            // Gerader Fall
            else
            {
                std::cout << "i: " << i << " , j: " << j << " := Gerade!" << std::endl;
            }
        }
    }
}
