#include <iostream>

void f(int v)
{
    std::cout << &v << '\n';
}

int main()
{
    int a = 2;
    std::cout << &a << '\n';

    f(a);

    return 0;
}
