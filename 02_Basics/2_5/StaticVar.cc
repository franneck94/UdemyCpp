#include <cstdint>
#include <iostream>

constexpr static int VALUE = 2;

int func(const int val)
{
    static int counter = 0;
    counter++;

    if (counter <= 3)
    {
        const int temp = val * 2;
        return temp / 3;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::cout << func(VALUE) << '\n';
    std::cout << func(VALUE) << '\n';
    std::cout << func(VALUE) << '\n';
    std::cout << func(VALUE) << '\n';

    return 0;
}
