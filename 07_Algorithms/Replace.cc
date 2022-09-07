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

bool replace_even(const std::int32_t i)
{
    return (i % 2 == 0);
}

int main()
{
    auto my_vector1 = std::vector<std::int32_t>{1, 2, 3, 4};
    print_vector(my_vector1);

    std::replace(my_vector1.begin(), my_vector1.end(), 2, 1337);
    print_vector(my_vector1);

    std::replace_if(my_vector1.begin(), my_vector1.end(), replace_even, -1);
    print_vector(my_vector1);

    return 0;
}
