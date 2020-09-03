// Hier die ben�tigten Includes und using Befehle
#include <iostream>

#include "exercise.h"

using std::cin;
using std::cout;
using std::endl;

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
				cout << "i: " << i << " , j: " << j << " := Ungerade!" << endl;
			}
			// Gerader Fall
			else
			{
				cout << "i: " << i << " , j: " << j << " := Gerade!" << endl;
			}
		}
	}
}