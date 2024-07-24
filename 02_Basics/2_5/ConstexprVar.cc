#include <cstdint>
#include <iostream>

constexpr int VALUE = 2;

int func(const int val)
{
    const int temp = val * 2;

    return temp / 3;
}

int main()
{
    constexpr int v = 2 * 3 * 5;
    std::cout << func(v) << '\n';

    return 0;
}
