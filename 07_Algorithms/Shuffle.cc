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
    auto my_vector1 = std::vector<std::int32_t>{1, 2, 3, 4};
    print_vector(my_vector1);

    auto seed_generator = std::random_device{};
    auto random_generator = std::mt19937_64{seed_generator()};

    std::shuffle(my_vector1.begin(), my_vector1.end(), random_generator);
    print_vector(my_vector1);

    return 0;
}
