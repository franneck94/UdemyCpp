#include <iostream>

void f(int val)
{
    std::cout << val << std::endl;
}

int main()
{
    int val = 0;

    // Post: Erst die Code Zeile ausfuehren, dann den Wert erhoehen
    // val2 = val + 1 (Innerhalb der Zeile)
    // val = val2 (Nach beenden der Zeile)

    // Pre: Erst den Wert erhoehen, dann den Rest der Code Zeile ausfuehren
    // val = val + 1 (Innerhalb der Zeile)

    //cout << val++ << std::endl; // 1
    //cout << ++val << std::endl; // 2

    for (int i = 0; i < 3; i++)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
