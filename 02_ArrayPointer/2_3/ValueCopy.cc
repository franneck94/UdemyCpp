#include <iostream>

void f(int v)
{
    std::cout << &v << std::endl;
}

int main()
{
    int a = 2;
    std::cout << &a << std::endl;

    f(a);

    return 0;
}
