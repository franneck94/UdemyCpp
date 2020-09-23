#include <iostream>

int main()
{
    // Heap allocation
    int *p_zahl = nullptr;
    p_zahl = new int{4};

    // The memory adress of the heap variable, where the pointer the points to
    std::cout << p_zahl << std::endl;
    if (p_zahl != nullptr)
    {
        // The value of the heap variable, where the pointer the points to
        std::cout << *p_zahl << std::endl;
        // Memory adress of the pointer itself
        std::cout << &p_zahl << std::endl;
    }

    // Heap de-allocation
    delete p_zahl;
    p_zahl = nullptr;

    // The memory adress of the heap variable, where the pointer the points to
    std::cout << p_zahl << std::endl;
    if (p_zahl != nullptr)
    {
        // The value of the heap variable, where the pointer the points to
        std::cout << *p_zahl << std::endl;
        // Memory adress of the pointer itself
        std::cout << &p_zahl << std::endl;
    }

    return 0;
}