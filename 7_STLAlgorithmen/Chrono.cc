#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using time_interval = std::chrono::microseconds;
constexpr std::size_t NUM_ELEMENTS = 1'000'000;

int main()
{
    std::vector<int> my_vector(NUM_ELEMENTS, 0);

    std::random_device seed_generator;
    std::mt19937 random_generator(42);
    std::uniform_int_distribution<int> random_distribution(-10, 10);

    auto start_time = std::chrono::high_resolution_clock::now();

    for (std::size_t i = 0; i < NUM_ELEMENTS; ++i)
    {
        my_vector[i] = random_distribution(random_generator);
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<time_interval>(end_time - start_time).count();
    std::cout << "The program took " << elapsed << " us" << std::endl;

    return 0;
}
