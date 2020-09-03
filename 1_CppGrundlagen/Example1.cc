#include <iostream>

int main()
{
    // User-Input: Seitenlaenge a eines Quadrats
    // Aufgabe: Berechne den Umfang und den Fleacheninhalt des Quadrats.
    // Gebe die berechneten Werte in der Konsole aus.

    double a = 0.0;
    std::cout << "Please enter the value for a: ";
    std::cin >> a;
    std::cout << "You entered: " << a << std::endl;

    double perimeter = 4 * a;
    double area = a * a;

    std::cout << "The perimeter is: " << perimeter << std::endl;
    std::cout << "The area is: " << area << std::endl;

    return 0;
}