#include <functional>
#include <iostream>

int f(int arg)
{
    std::cout << arg << '\n';

    return ++arg;
}

int new_approach2(std::function<int(int)> func)
{
    return func(2);
}

int main()
{
    auto param = int{1};

    // Old C-style approach
    int (*old_approach)(int);
    old_approach = f;
    old_approach(2);

    // C++ approach
    auto new_approach = std::function{f};
    auto result = new_approach(param);

    new_approach2(f);

    return 0;
}
