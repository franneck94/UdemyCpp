#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

void print_vector(const std::vector<std::int32_t> &my_vector)
{
    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << "Vec[" << i << "] = " << my_vector[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    const auto my_vector1 = std::vector<std::int32_t>{1, 2, 3, 4};
    print_vector(my_vector1);

    const auto result1 = std::reduce(my_vector1.begin(), my_vector1.end());
    std::cout << result1 << std::endl;

    const auto result2 = std::reduce(my_vector1.begin(), my_vector1.end(), 2);
    std::cout << result2 << std::endl;

    return 0;
}
