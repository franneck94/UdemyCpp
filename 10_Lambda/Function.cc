#include <functional>
#include <iostream>

void f1(int arg)
{
    std::cout << arg << '\n';
}

int f2(int arg)
{
    std::cout << arg << '\n';

    return ++arg;
}

int func3(std::function<int(int)> func)
{
    return func(2);
}

int main()
{
    auto param = int{1};

    auto func1 = std::function{f1};
    func1(param);
    auto func2 = std::function{f2};
    auto result = func2(param);

    func3(f2);

    return 0;
}
