#include <iostream>
#include <vector>

generator<int> generatorForNumbers(int begin, int inc = 1)
{
    for (int i = begin;; i += inc)
    {
        co_yield i;
    }
}

int main()
{
    const auto numbers = generatorForNumbers(-10);

    for (int i = 1; i <= 20; ++i)
        std::cout << numbers << " ";

    return 0;
}
