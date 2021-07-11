#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

void random_vector(std::vector<int> &vec)
{
    std::random_device seed_generator;
    std::mt19937 random_generator(seed_generator());
    std::uniform_int_distribution<int> random_distribution(-10, 10);

    for (auto &val : vec)
    {
        val = random_distribution(random_generator);
    }
}

bool replace_even(int i)
{
    if (i % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    std::vector<int> vector_a(3, 0);
    std::vector<int> vector_b(3, 0);
    std::vector<int> vector_c(3, 0);

    random_vector(vector_a);
    random_vector(vector_b);
    random_vector(vector_c);

    // REPLACE
    for (const auto &val : vector_c)
    {
        std::cout << val << std::endl;
    }

    std::replace_if(vector_c.begin(), vector_c.end(), replace_even, 1);

    for (const auto &val : vector_c)
    {
        std::cout << val << std::endl;
    }

    // SHUFFLE
    for (const auto &val : vector_c)
    {
        std::cout << val << std::endl;
    }

    std::random_device seed_generator;
    std::mt19937 random_generator(seed_generator());
    std::shuffle(vector_c.begin(), vector_c.end(), random_generator);

    for (const auto &val : vector_c)
    {
        std::cout << val << std::endl;
    }

    return 0;
}
