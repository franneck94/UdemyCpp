#include <future>
#include <iostream>

int function(const int input)
{
    std::cout << input << '\n';

    return input * 2;
}

int main()
{
    int input = 1;
    auto handle = std::async(std::launch::async, function, input);

    // ...

    auto result = handle.get();
    std::cout << result << '\n';

    return 0;
}
