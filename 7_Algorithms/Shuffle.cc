#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>

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

    std::iota(my_vector1.begin(), my_vector1.end(), 1);
    print_vector(my_vector1);

    std::random_device seed_generator{};
    std::mt19937_64 random_generator{seed_generator()};

    std::shuffle(my_vector1.begin(), my_vector1.end(), random_generator);
    print_vector(my_vector1);

    return 0;
}
