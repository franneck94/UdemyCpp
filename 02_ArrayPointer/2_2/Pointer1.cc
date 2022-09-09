#include <iostream>

// &: Reference
// *p: De-reference

int main()
{
    int number = 5;
    std::cout << "Value of number: " << number << std::endl;
    std::cout << "Address of number: " << &number << std::endl; // 3c

    int *p = &number;
    std::cout << "Value of p: " << p << std::endl;                                   // 3c
    std::cout << "Value of the memory address that p points to: " << *p << std::endl; // 3c

    return 0;
}
