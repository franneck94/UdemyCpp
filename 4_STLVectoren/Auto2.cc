#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    // 1: auto val : vec => int val : vec
    // 2: auto &val : vec => int& val : vec
    // 3: const auto &val : vec => const int& val : vec
    // 4: const auto val : vec => const int val : vec

    std::vector<int> vec(10, 0);
    std::iota(vec.begin(), vec.end(), 1);

    for (const auto &val : vec)
    {
        std::cout << val << " " << &val << std::endl;
    }

    std::cout << std::endl;

    for (unsigned int i = 0; i < 10; i++)
    {
        std::cout << vec[i] << " " << &vec[i] << std::endl;
    }

    return 0;
}
