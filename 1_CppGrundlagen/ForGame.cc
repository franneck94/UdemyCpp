#include <iostream>

int main()
{
    int anzahl_spiele;

    std::cout << "Willkommen bei meinem Gluecks-Spiel!" << std::endl;
    std::cout << "Wie viele Spiel-Durchlaeufe willst du spielen: ";
    std::cin >> anzahl_spiele;

    for (int i = 0; i < anzahl_spiele; i++)
    {
        int zahl;
        std::cout << "Du bist im Spieldurchlauf Nummer: " << i << std::endl;
        std::cout << "Bitte gebe eine Zahl aus dem Intervall [1, 10] ein: ";
        std::cin >> zahl;

        if (zahl >= 1 && zahl <= 10)
        {
            if (zahl == 4)
            {
                std::cout << "Du hast den Haupt-Preis gewonnen!" << std::endl;
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
            std::cout << "Du hast leider eine Zahl eingegeben, die nicht aus dem Intervall [1, 10] stammt!"
                      << std::endl;
        }
    }

    return 0;
}