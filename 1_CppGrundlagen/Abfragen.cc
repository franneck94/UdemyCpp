#include <iostream>

int main()
{
    bool bin_ich_pleite = false;

    if (bin_ich_pleite == true)
    {
        std::cout << "Ich bin pleite!";
    }
    else
    {
        std::cout << "Ich bin nicht pleite!";
    }

    int zahl;
    std::cout << "Willkommen bei meinem Gluecks-Spiel!" << std::endl;
    std::cout << "Bitte gebe eine Zahl aus dem Intervall [1, 10] ein: ";
    std::cin >> zahl;

    // Vergleichs-Operatoren:
    // Gleichheit (==), Kleiner Gleich (<=), Groesser Gleich (>=)
    // Un-Gleichheit (!=), Kleiner (<), Groesser (>)

    // Logische Verknüfungen:
    // Und (&&), Oder (||)

    if (zahl >= 1 && zahl <= 10)
    {
        // Haupt-Preis bei der Zahl 4
        // Trost-Preis, wenn der User eine Zahl eingibt, die durch 2 teilbar ist
        // [2, 6, 8, 10]
        // Ansonsten, hat man verloren
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
        std::cout << "Du hast leider eine Zahl eingegeben, die nicht aus dem "
                     "Intervall [1, 10] stammt!"
                  << std::endl;
    }

    return 0;
}
