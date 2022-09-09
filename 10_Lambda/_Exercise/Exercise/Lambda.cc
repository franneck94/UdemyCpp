#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(1, 52);

    std::vector<int> my_vector(10, 0);
    std::vector<int> my_result(10, 0);
    std::generate(my_vector.begin(), my_vector.end(), [&]() -> int {
        return dist(gen);
    });

    for (const auto &val : my_vector)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    // Exercise 1


    // Exercise 2


    return 0;
}
