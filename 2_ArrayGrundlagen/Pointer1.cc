#include <iostream>

int main()
{
    int number = 1337;
    std::cout << "Value of number: " << number << std::endl;
    std::cout << "Memory adress of number: " << &number << std::endl;

    // Pointer muss auf eine Speicheradresse zeigen
    // p: Memory Adress
    // *p: Value of that memory adress
    int *p = &number;
    std::cout << "The memory adress that the variable 'p' points to: " << p
              << std::endl;
    std::cout << "The value that the variable 'p' points to: " << *p
              << std::endl;

    return 0;
}
