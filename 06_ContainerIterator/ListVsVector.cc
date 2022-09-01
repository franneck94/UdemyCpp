#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

#include "Timer.h"

constexpr static auto NUM_RUNS = std::size_t{5};
constexpr static auto ELEMENTS = std::size_t{100'000};

#define USING_VEC

#ifdef USING_VEC
using Container_t = std::vector<std::int32_t>;
#else
using Container_t = std::list<std::int32_t>;
#endif

/*
1. Insert
2. Delete
3. Iterate over all
4. Random Index

Vector:
Insert: 2014.2 ms
Delete: 643.2 ms
Sum: 36 us
Random Index: 522.4 us
= 2.657ms

List:
Insert: 5.2ms
Delete: 4.4ms
Sum: 204.6 us
Random Index:
= 5.818 ms
*/

Container_t generate_container()
{
    auto gen = std::mt19937{0};
    auto dist = std::uniform_int_distribution<std::int32_t>{-100, 100};

    auto c = Container_t(ELEMENTS, 0);
    std::generate(c.begin(), c.end(), [&]() { return dist(gen); });

    return c;
}

void insertion(Container_t &c)
{
    auto it = c.begin();

    for (std::size_t i = 0; i < ELEMENTS; ++i)
    {
        it = c.insert(it, 0);
    }
}

void deletion(Container_t &c)
{
    for (std::size_t i = 0; i < ELEMENTS - 1; ++i)
    {
        c.erase(c.begin());
    }
}

void summing(Container_t &c)
{
    volatile auto sum = std::uint64_t{0};

    for (const auto &val : c)
    {
        sum += val;
    }
}

#ifdef USING_VEC
void indexing(std::vector<std::int32_t> &c)
{
    auto gen = std::mt19937{0};
    auto dist = std::uniform_int_distribution<std::size_t>{0, ELEMENTS};

    auto index = std::size_t{0};
    for (std::size_t i = 0; i < ELEMENTS; ++i)
    {
        index = dist(gen);
        c[index] = 42;
    }
}
#else
void indexing(std::list<std::int32_t> &c)
{
    std::random_device gen;
    std::uniform_int_distribution<std::size_t> dist(0, ELEMENTS);

    auto index = std::size_t{0};
    for (std::size_t i = 0; i < ELEMENTS; ++i)
    {
        index = dist(gen);
        auto it = c.begin();

        for (std::size_t j = 0; j < index; ++j)
        {
            ++it;
        }

        *it = 42;
    }
}
#endif

std::int32_t main()
{
    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            Container_t c = generate_container();
            cpptiming::Timer t;
            insertion(c);
            total_time += t.elapsed_time<cpptiming::millisecs, double>();
        }

        std::cout << "Insert: " << total_time / NUM_RUNS << " ms" << std::endl;
    }

    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            Container_t c = generate_container();
            cpptiming::Timer t;
            deletion(c);
            total_time += t.elapsed_time<cpptiming::millisecs, double>();
        }

        std::cout << "Delete: " << total_time / NUM_RUNS << " ms" << std::endl;
    }

    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            Container_t c = generate_container();
            cpptiming::Timer t;
            summing(c);
            total_time += t.elapsed_time<cpptiming::microsecs, double>();
        }

        std::cout << "Sum: " << total_time / NUM_RUNS << " us" << std::endl;
    }

    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            Container_t c = generate_container();
            cpptiming::Timer t;
            indexing(c);
            total_time += t.elapsed_time<cpptiming::microsecs, double>();
        }

        std::cout << "Random Index: " << total_time / NUM_RUNS << " us" << std::endl;
    }

    return 0;
}
