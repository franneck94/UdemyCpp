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

int main()
{
    std::vector<int> my_vector1(10, 0);
    std::vector<int> my_vector2(10, 0);
    std::vector<int> my_vector3(10, 0);

    std::iota(my_vector1.begin(), my_vector1.end(), 0);
    print_vector(my_vector1);

    auto result1 = std::reduce(my_vector1.begin(), my_vector1.end());
    std::cout << result1 << std::endl;

    auto result2 = std::reduce(my_vector1.begin(), my_vector1.end(), 2);
    std::cout << result2 << std::endl;

    return 0;
}
