#include <iostream>

consteval int func(int n)
{
    return n * 2;
}

int main()
{
    int a[func(3)] = {};

    constexpr int b = 3;
    func(b);

    const int c = 3;
    func(c);

    return 0;
}
