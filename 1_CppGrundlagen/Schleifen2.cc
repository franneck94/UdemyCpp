#include <iostream>

int main()
{
    int zahl = 4;

    do
    {
        std::cout << std::endl
                  << "Gebe eine Zahl ein (1-10)" << std::endl;
        std::cin >> zahl;

        // HP: 4, TP: Durch 2 Teilbar und nicht 4
        if (zahl < 1 || zahl > 10)
        {
            std::cout << std::endl
                      << "Falsche Eingabe" << std::endl;
        }
        // Wenn Zahl ist gleich 4, dann gewonnen
        // HP
        else if (zahl == 4)
        {
            std::cout << std::endl
                      << "Gewonnen! HP" << std::endl;
        }
        // TP
        else if (zahl % 2 == 0)
        {
            std::cout << std::endl
                      << "Gewonnen! TP" << std::endl;
        }
        // Ansonsten verloren
        // Niete
        else
        {
            std::cout << std::endl
                      << "Verloren!" << std::endl;
        }
    } while (zahl != 4 && zahl % 2 != 0);

    int i = 0;
    while (i < 10)
    {
        // TODO

        i += 2;
    }

    return 0;
}