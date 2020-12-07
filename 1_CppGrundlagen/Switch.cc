#include <iostream>

int main()
{
    char auswahl;
    std::cout << "Waehle einen Schokoriegel (a-d): ";
    std::cin >> auswahl;

    switch (auswahl)
    {
        case 'a':
            std::cout << "Du erhaelst einen Aounty" << std::endl;
            break;
        case 'b':
            std::cout << "Du erhealst ein Bwix" << std::endl;
            break;
        case 'c':
            std::cout << "Du erhealst ein Vars" << std::endl;
            break;
        case 'd':
            std::cout << "Du erhealst ein Lickers" << std::endl;
            break;
        default:
            std::cout << "Falsche Eingabe!" << std::endl;
    }

    return 0;
}