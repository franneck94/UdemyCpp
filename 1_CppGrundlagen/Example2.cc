#include <iostream>

#define PI 3.14159

int main()
{
    // User-Input: Radius r eines Kreises einlesen
    // Aufgabe: Berechne den Umfang und den Fleacheninhalt des Kreises.
    // Gebe die berechneten Werte in der Konsole aus.

    double radius;
    std::cout << "Please enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "You entered the radius: " << radius << std::endl;

    double perimeter = 2 * PI * radius;
    double area = PI * radius * radius;

    std::cout << "The perimeter of the circle is: " << perimeter << std::endl;
    std::cout << "The area of the circle is: " << area << std::endl;

    return 0;
}
