#include <iostream>

// Local copy (Call by Value)
void f(int *p_function)
{
    std::cout << "Function f: " << std::endl;
    std::cout << "Adress of p_function pointer location on the heap (inside):" << p_function << std::endl; // 015BF040
    std::cout << "Adress of p_function:" << &p_function << std::endl
              << std::endl; // 00F7F8BC
}

// Reference (&): Call-by-Reference
void f2(int *&p_function)
{
    std::cout << "Function f2: " << std::endl;
    std::cout << "Adress of p_function pointer location on the heap (inside):" << p_function << std::endl; // 015BF040
    std::cout << "Adress of p_function:" << &p_function << std::endl
              << std::endl; // 00F7F8B8
}

// Local copy (Call by Value)
void g(int number)
{
    std::cout << "Function g: " << std::endl;
    std::cout << "Adress of number (inside):" << &number << std::endl; // 00F7F8BC
}

// Reference (&): Call-by-Reference
void g2(int &number)
{
    std::cout << "Function g2: " << std::endl;
    std::cout << "Adress of number (inside):" << &number << std::endl; // 00F7F8C0
}

int main()
{
    int *p_number = new int{4};

    std::cout << "Adress of p_number pointer location on the heap (outside):" << p_number << std::endl; // 015BF040
    std::cout << "Adress of p_number (outside):" << &p_number << std::endl
              << std::endl; // 00F7F8B8

    f(p_number);
    f2(p_number);

    int normal_number = 7;

    std::cout << "Adress of normal_number (inside):" << &normal_number << std::endl; // 00F7F8C0

    g(normal_number);
    g2(normal_number);

    delete p_number;

    return 0;
}