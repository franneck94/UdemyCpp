#include <iostream>

// &: Reference
// *p: De-reference

int main()
{
    int number = 5;
    std::cout << "Value of number: " << number << '\n';
    std::cout << "Address of number: " << &number << '\n'; // 3c

    int *p = &number;
    std::cout << "Value of p: " << p << '\n';                              // 3c
    std::cout << "Value of the mem addr that p points to: " << *p << '\n'; // 3c

    return 0;
}
