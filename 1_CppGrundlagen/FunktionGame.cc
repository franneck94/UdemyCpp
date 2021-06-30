#include <iostream>

// Bevor eine Funktion aufgerufen werden kann, muss sie zumindest
// vorher deklariert sein. Zeitgleich muss sie aber an anderer Stelle
// im Code auch definiert sein.

// Deklaration
void game();

int main()
{
    // Aufruf
    game();

    return 0;
}

// Definition
void game()
{
    bool gewonnen = false;
    std::cout << "Willkommen bei meinem Gluecks-Spiel!" << std::endl;

    while (gewonnen == false)
    {
        int zahl;
        std::cout << "Bitte gebe eine Zahl aus dem Intervall [1, 10] ein: ";
        std::cin >> zahl;

        if (zahl >= 1 && zahl <= 10)
        {
            if (zahl == 4)
            {
                std::cout << "Du hast den Haupt-Preis gewonnen!" << std::endl;
                gewonnen = true;
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
            std::cout << "Du hast leider eine Zahl eingegeben, die nicht aus "
                         "dem Intervall [1, 10] stammt!"
                      << std::endl;
        }
    }
}
