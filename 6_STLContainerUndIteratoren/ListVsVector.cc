#include <iostream>
#include <vector>
#include <list>
#include <numeric>

#include "Timer.h"

constexpr std::size_t LEN = 100;
constexpr std::size_t NUM_INSERTS = 100'000;

void vec_time()
{
    std::vector<int> data(LEN, 0);
    std::iota(data.begin(), data.end(), 0);

    std::vector<int> my_data(data.begin(), data.end());
    auto it = my_data.begin();

    for (std::size_t i = 0; i < NUM_INSERTS; ++i)
    {
        // it = my_data.insert(it, 0);
        my_data.push_back(0);
    }
}

void list_time()
{
    std::vector<int> data(LEN, 0);
    std::iota(data.begin(), data.end(), 0);

    std::list<int> my_data(data.begin(), data.end());

    for (std::size_t i = 0; i < NUM_INSERTS; ++i)
    {
        my_data.push_back(0);
    }
}

int main()
{
    int num_runs = 10;
    double total_time = 0.0;

    for (int i = 0; i < num_runs; ++i)
    {
        cpptiming::Timer t;
        vec_time();
        total_time += t.elapsed_time<cpptiming::millisecs, double>();
    }

    std::cout << "Mean time for Vector: " << total_time / num_runs << " ms" << std::endl;

    total_time = 0.0;

    for (int i = 0; i < num_runs; ++i)
    {
        cpptiming::Timer t;
        list_time();
        total_time += t.elapsed_time<cpptiming::millisecs, double>();
    }

    std::cout << "Mean time for List: " << total_time / num_runs << " ms" << std::endl;

    return 0;
}
