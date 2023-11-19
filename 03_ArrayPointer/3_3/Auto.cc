#include <iostream>

int &f(int a)
{
    return a;
}

int main()
{
    int i = 2;
    int *j = &i;
    auto k = &i;

    int &l = i;
    auto &m = i;

    auto &n = f(i);

    return 0;
}
