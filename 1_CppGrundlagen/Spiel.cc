#include <iostream>

#include "Spiel.h"

// Definition
void game()
{
	// b_gewonnen
	bool b_gewonnen = false;
	std::cout << "Willkommen bei meinem Gluecks-Spiel!" << std::endl;

	while (b_gewonnen == false)
	{
		int zahl;
		std::cout << "Bitte gebe eine Zahl aus dem Intervall [1, 10] ein: ";
		std::cin >> zahl;

		if (zahl >= 1 && zahl <= 10)
		{
			if (zahl == 4)
			{
				std::cout << "Du hast den Haupt-Preis gewonnen!" << std::endl;
				b_gewonnen = true;
			}
			else if (zahl % 2 == 0)
			{
				std::cout << "Du hast einen Trost-Preis gewonnen!" << std::endl;
			}
			else
			{
				std::cout << "Du hast verloren!" << std::endl;
			}
		}
		else
		{
			std::cout << "Du hast leider eine Zahl eingegeben, die nicht aus dem Intervall [1, 10] stammt!" << std::endl;
		}
	}
}