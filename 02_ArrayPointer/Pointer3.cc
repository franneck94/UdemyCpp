#include <iostream>

int main()
{
    // Heap allocation
    int *p_zahl = new int{4};

    // Heap de-allocation
    delete p_zahl;

    // The memory adress of the heap variable, where the pointer the points to
    std::cout << p_zahl << std::endl;

    p_zahl = nullptr;

    // The memory adress of the heap variable, where the pointer the points to
    std::cout << p_zahl << std::endl;

    if (p_zahl != nullptr)
    {
        std::cout << *p_zahl << std::endl;
    }

    return 0;
}
