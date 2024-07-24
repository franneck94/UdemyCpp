#include <cstdint>
#include <iostream>

int func(const int val)
{
    static int counter = 0;

    const int temp = val * 2;

    ++counter;
    std::cout << "Counter: " << counter << "\n";

    return temp / 3;
}

int main()
{
    std::cout << func(1) << '\n';
    std::cout << func(2) << '\n';
    std::cout << func(3) << '\n';

    return 0;
}
