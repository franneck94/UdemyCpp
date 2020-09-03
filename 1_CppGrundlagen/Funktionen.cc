#include <iostream>

// Rueckgabe-Typ Funktions-Namen (Argumente)
bool is_even(int number)
{
    if (number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int zahl1 = 3;
    bool antwort1 = is_even(zahl1);
    std::cout << antwort1 << std::endl;

    int zahl2 = 4;
    bool antwort2 = is_even(zahl2);
    std::cout << antwort2 << std::endl;

    int zahl3 = 5;
    bool antwort3 = is_even(zahl3);
    std::cout << antwort3 << std::endl;

    return 0;
}