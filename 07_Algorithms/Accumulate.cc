#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

void print_vector(const std::vector<int> &my_vector)
{
    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << "Vec[" << i << "] = " << my_vector[i] << std::endl;
    }
    std::cout << std::endl;
}

int adder(int i, int j)
{
    return i + j;
}

int multiplier(int i, int j)
{
    return i * j;
}

int main()
{
    std::vector<int> my_vector1(10, 0);
    std::vector<int> my_vector2(10, 0);
    std::vector<int> my_vector3(10, 0);

    std::iota(my_vector1.begin(), my_vector1.end(), 1);
    print_vector(my_vector1);

    auto result1 = std::accumulate(my_vector1.begin(), my_vector1.end(), 0);
    std::cout << result1 << std::endl;

    auto result2 = std::accumulate(my_vector1.begin(), my_vector1.end(), 0, adder);
    std::cout << result2 << std::endl;

    auto result3 = std::accumulate(my_vector1.begin(), my_vector1.end(), 1, multiplier);
    std::cout << result3 << std::endl;

    return 0;
}
