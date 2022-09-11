#include <iostream>

// 1a. C++: static_cast<newDtype>(varName)
// 1b. C: (newDtype)(varName)
// Easier to read, less prone to errors

int main()
{
    // C++
    int a = 12;
    float b = static_cast<float>(a);

    double c = 12.3;
    float d = static_cast<float>(c);

    // C
    short e = 256;
    char f = (char)(e);

    return 0;
}
