#include <functional>
#include <iostream>
#include <vector>

int main()
{
    const int threshold = 2;
    auto fns = std::vector<std::function<bool(const int)>>{
        [&threshold](const int v) { return v > threshold; },
        [&threshold](const int v) { return v < threshold; },
        [&threshold](const int v) { return v == threshold; },
        [&threshold](const int v) { return v != threshold; },
        [&threshold](const int v) { return v >= threshold; },
        [&threshold](const int v) { return v <= threshold; },
    };

    // auto fns = std::vector<bool (*)(const int)>{
    //     [](const int v) { return v > 2; },
    //     [](const int v) { return v < 2; },
    //     [](const int v) { return v == 2; },
    //     [](const int v) { return v != 2; },
    //     [](const int v) { return v >= 2; },
    //     [](const int v) { return v <= 2; },
    // };

    for (const auto &fn : fns)
    {
        std::cout << std::boolalpha << fn(1) << '\n';
    }

    return 0;
}
