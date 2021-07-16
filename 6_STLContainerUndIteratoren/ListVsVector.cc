#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <typeinfo>
#include <vector>

#include "Timer.h"

constexpr std::size_t NUM_RUNS = 5;
constexpr std::size_t ELEMENTS = 100'000;

#define lst

#ifdef vec
using container = std::vector<int>;
#else
using container = std::list<int>;
#endif

/*
1. Insert
2. Delete
3. Iterate over all
4. Random Index

Vector:
Insert: 1316 ms
Delete: 365 ms
Sum: 80 ns
Random Index: 27.8 ms
= 1,710 ms

List:
Insert: 0.6 ms
Delete: 0.8 ms
Sum: 100 ns
Random Index: 10816.4 ms
= 10,800 ms
*/

container generate_container()
{
    std::mt19937 gen(0);
    std::uniform_int_distribution<int> dist(-100, 100);

    container c(ELEMENTS);
    std::generate(c.begin(), c.end(), [&]() { return dist(gen); });

    return c;
}

void insertion(container &c)
{
    auto it = c.begin();

    for (std::size_t i = 0; i < ELEMENTS; ++i)
    {
        it = c.insert(it, 0);
    }
}

void deletion(container &c)
{
    for (std::size_t i = 0; i < ELEMENTS - 1; ++i)
    {
        c.erase(c.begin());
    }
}

void summing(container &c)
{
    long long sum = 0;

    for (const auto &val : c)
    {
        sum += val;
    }
}

void indexing_vec(std::vector<int> &c)
{
    int index = 0;
    std::random_device gen;
    std::uniform_int_distribution<int> dist(0, ELEMENTS);

    for (std::size_t i = 0; i < ELEMENTS; ++i)
    {
        index = dist(gen);
        c[index] = 42;
    }
}

void indexing_list(std::list<int> &c)
{
    int index = 0;
    std::random_device gen;
    std::uniform_int_distribution<int> dist(0, ELEMENTS);

    for (std::size_t i = 0; i < ELEMENTS; ++i)
    {
        index = dist(gen);
        auto it = c.begin();

        for (int j = 0; j < index; ++j)
        {
            it++;
        }

        *it = 42;
    }
}

int main()
{
#ifdef vec
    std::cout << "Vector: " << std::endl;
#else
    std::cout << "List: " << std::endl;
#endif

    {
        double total_time = 0.0;

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            container c = generate_container();
            cpptiming::Timer t;
            insertion(c);
            total_time += t.elapsed_time<cpptiming::millisecs, double>();
        }

        std::cout << "Insert: " << total_time / NUM_RUNS << " ms" << std::endl;
    }

    {
        double total_time = 0.0;

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            container c = generate_container();
            cpptiming::Timer t;
            deletion(c);
            total_time += t.elapsed_time<cpptiming::millisecs, double>();
        }

        std::cout << "Delete: " << total_time / NUM_RUNS << " ms" << std::endl;
    }

    {
        double total_time = 0.0;

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            container c = generate_container();
            cpptiming::Timer t;
            summing(c);
            total_time += t.elapsed_time<cpptiming::nanosecs, double>();
        }

        std::cout << "Sum: " << total_time / NUM_RUNS << " ns" << std::endl;
    }

    {
        double total_time = 0.0;

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            container c = generate_container();
            cpptiming::Timer t;
#ifdef vec
            indexing_vec(c);
#else
            indexing_list(c);
#endif
            total_time += t.elapsed_time<cpptiming::millisecs, double>();
        }

        std::cout << "Random Index: " << total_time / NUM_RUNS << " ms" << std::endl;
    }

    return 0;
}
