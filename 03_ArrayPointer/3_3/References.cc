#include <iostream>

void f1(int v)
{
    std::cout << "f1: " << v << '\n';
    std::cout << &v << '\n';
}

void f2(int *const v)
{
    std::cout << "f2: " << *v << '\n';
    std::cout << v << '\n';
}

void f3(int &v)
{
    std::cout << "f3: " << v << '\n';
    std::cout << &v << '\n';
}

int main()
{
    int a = 2;
    std::cout << &a << '\n';

    f1(a);
    f2(&a);
    f3(a);

    return 0;
}
