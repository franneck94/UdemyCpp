#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <string>
#include <thread>
#include <vector>

#include "Matrix.h"
#include "Timer.h"
#include "omp.h"

using std::string;
using std::vector;

int main()
{
    // SETUP
    std::random_device gen;
    std::uniform_int_distribution<int> dist(-10, 10);
    vector<int> vector_a(10'000'000, 0);
    std::generate(vector_a.begin(), vector_a.end(), [&]() { return dist(gen); });
    long long sum_vector = 0;

    // SERIELL
    {
        Timer t;
        sum_vector = serial_sum(vector_a);
        std::cout << std::endl << "Serial Sum: " << sum_vector << std::endl;
    }

    // PARALLEL
    {
        Timer t;
        sum_vector = parallel_sum(vector_a);
        std::cout << std::endl << "Parallel Sum: " << sum_vector << std::endl;
    }

    // REDUCE
    {
        Timer t;
        sum_vector = std::reduce(vector_a.begin(), vector_a.end());
        std::cout << std::endl << "Reduce Sum: " << sum_vector << std::endl;
    }

    // ACCUMULATE
    {
        Timer t;
        sum_vector = std::accumulate(vector_a.begin(), vector_a.end(), 0, std::plus<int>());
        std::cout << std::endl << "Accumulate Sum: " << sum_vector << std::endl;
    }

    return 0;
}