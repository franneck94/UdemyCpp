#include <iostream>

// void f(int v) // lvalue: 5
// void f(const int v) // const lvalue: 5
// void f(int &v) // lvalue &: 2
// void f(const int &v) // const lvalue &: 5

void f(const int &v) // const lvalue &
{
    std::cout << v << '\n';
}

int main()
{
    int a = 2;        // lvalue
    const int b = 2;  // const lvalue
    int &c = a;       // lvalue reference
    const int &d = b; // const lvalue reference

    f(a);
    f(b);
    f(c);
    f(d);
    f(2); // rvalue

    return 0;
}
