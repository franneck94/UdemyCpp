#include <iostream>

void f(int *p_function)
{
    std::cout << "(FUNC):  p_function = " << p_function << '\n';
    std::cout << "(FUNC): &p_function = " << &p_function << '\n';
}

int main()
{
    int *p_number = new int{4};

    std::cout << "(MAIN):  p_number = " << p_number << '\n';
    std::cout << "(MAIN): &p_number = " << &p_number << '\n';

    f(p_number);

    return 0;
}
