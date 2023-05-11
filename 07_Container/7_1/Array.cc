#include <array>
#include <iostream>
#include <vector>

constexpr static auto ARRAY_LEN = 3U;

int main()
{
    const auto vec = std::vector<int>{1, 2, 3};
    const auto arr = std::array<int, ARRAY_LEN>{1, 2, 3};

    std::cout << vec.size() << '\n';
    std::cout << arr.size() << '\n';

    std::cout << vec.empty() << '\n';
    std::cout << arr.empty() << '\n';

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    for (const auto val : vec)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    for (const auto val : arr)
    {
        std::cout << val << ' ';
    }

    return 0;
}
