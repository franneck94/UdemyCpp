#include <iostream>
#include <vector>

// 1: auto val : vec => int val : vec
// 2: auto& val : vec => int& val : vec
// 3: const auto val : vec => const int val : vec
// 4: const auto& val : vec => const int& val : vec
int main()
{
    auto vec = std::vector<int>{1, 2, 3, 4, 5};

    for (auto val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    for (auto &val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    for (const auto val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    for (const auto &val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    return 0;
}
