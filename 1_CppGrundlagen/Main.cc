#include <iostream>

int main()
{
    double zahl1;
    double zahl2;
    double ergebnis;

    std::cout << "Bitte gebe eine Zahl ein: ";
    std::cin >> zahl1;
    std::cout << "Bitte gebe eine weitere Zahl ein: ";
    std::cin >> zahl2;

    // Rechenoperationen: Mult *, Add +, Subtr -, Div /
    ergebnis = zahl1 * zahl2;
    std::cout << "Ergebnis Multiplikation: " << ergebnis << std::endl;

    ergebnis = zahl1 + zahl2;
    std::cout << "Ergebnis Addition: " << ergebnis << std::endl;

    ergebnis = zahl1 - zahl2;
    std::cout << "Ergebnis Subtraktion: " << ergebnis << std::endl;

    ergebnis = zahl1 / zahl2;
    std::cout << "Ergebnis Division: " << ergebnis << std::endl;

    return 0;
}