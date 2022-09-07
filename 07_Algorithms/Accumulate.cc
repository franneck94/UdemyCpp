#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

void print_vector(const std::vector<std::uint32_t> &my_vector)
{
    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << "Vec[" << i << "] = " << my_vector[i] << '\n';
    }
    std::cout << '\n';
}

std::uint32_t adder(const std::uint32_t i, const std::uint32_t j)
{
    return i + j;
}

std::uint32_t multiplier(const std::uint32_t i, const std::uint32_t j)
{
    return i * j;
}

int main()
{
    const auto my_vector1 = std::vector<std::uint32_t>{1, 2, 3, 4};
    auto my_vector2 = std::vector<std::uint32_t>(0, 4);
    auto my_vector3 = std::vector<std::uint32_t>(0, 4);

    print_vector(my_vector1);

    const auto result1 = std::accumulate(my_vector1.begin(), my_vector1.end(), 0);
    std::cout << result1 << '\n';

    const auto result2 =
        std::accumulate(my_vector1.begin(), my_vector1.end(), 0, adder);
    std::cout << result2 << '\n';

    const auto result3 =
        std::accumulate(my_vector1.begin(), my_vector1.end(), 1, multiplier);
    std::cout << result3 << '\n';

    return 0;
}
