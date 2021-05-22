#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int main()
{
    std::vector<int> my_vector(1'000'000, 0);

    std::mt19937 random_generator(42);
    std::uniform_int_distribution<int> random_distribution(-10, 10);

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10; ++i)
    {
        my_vector[i] = random_distribution(random_generator);
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    double elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    std::cout << "The program took " << elapsed_microseconds << " us." << std::endl;

    return 0;
}
