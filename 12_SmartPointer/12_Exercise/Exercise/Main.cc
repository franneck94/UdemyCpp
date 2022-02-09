#include <iostream>
#include <memory>

template <typename T>
auto my_function1(const std::unique_ptr<T> &unique_ptr)
{
    std::cout << unique_ptr[0] << std::endl;
    std::cout << unique_ptr[1] << std::endl;
    std::cout << unique_ptr[2] << std::endl;
}

template <typename U>
auto my_function2(std::shared_ptr<U> shared_ptr)
{
    std::cout << shared_ptr.use_count() << std::endl;
}

/**
 Aufgaben:
 1.) Finde den Fehler beim Erstellen des unique_ptr in der Main Funktion.
 2.) Was ist der use_count in Zeile 21 und 35 (ohne den Code auszuführen)?
 */
int main()
{
    std::unique_ptr<int[]> ptr1 = std::make_unique<int[]>(3);
    ptr1[0] = 42;
    ptr1[1] = 62;
    ptr1[2] = 82;
    my_function1<int[]>(ptr1);

    std::shared_ptr<double> ptr2 = std::make_shared<double>(10.0);
    my_function2<double>(ptr2);
    std::cout << ptr2.use_count() << std::endl;

    return 0;
}
