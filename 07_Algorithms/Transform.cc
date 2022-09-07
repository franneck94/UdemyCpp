#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

std::int32_t increment(const std::int32_t i)
{
    return i + 1;
}

std::int32_t add(const std::int32_t i, const std::int32_t j)
{
    return i + j;
}

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
    auto my_vector1 = std::vector<std::int32_t>{1, 2, 3, 4};
    auto my_vector2 = std::vector<std::int32_t>{1, 2, 3, 4};
    auto my_vector3 = std::vector<std::int32_t>{1, 2, 3, 4};

    std::iota(my_vector1.begin(), my_vector1.end(), 0);
    print_vector(my_vector1);

    std::transform(my_vector1.begin(),
                   my_vector1.end(),
                   my_vector2.begin(),
                   increment);
    print_vector(my_vector2);

    std::transform(my_vector1.begin(),
                   my_vector1.end(),
                   my_vector2.begin(),
                   my_vector3.begin(),
                   add);
    print_vector(my_vector3);

    return 0;
}
