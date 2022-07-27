#include <functional>
#include <iostream>
#include <vector>

int main()
{
    auto fns = std::vector<std::function<bool(const int)>>{
        [](const int v) { return v > 2; },
        [](const int v) { return v < 2; },
        [](const int v) { return v == 2; },
        [](const int v) { return v != 2; },
        [](const int v) { return v >= 2; },
        [](const int v) { return v <= 2; },
    };

    for (const auto &fn : fns)
    {
        std::cout << std::boolalpha << fn(2) << '\n';
    }

    return 0;
}
