#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

#include "Timer.h"

namespace
{
constexpr auto NUM_RUNS = std::size_t{5};
constexpr auto ELEMENTS = std::size_t{100'000};
} // namespace


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

Timings with MSVC 2022 - x64 with /Ox /GL

Vector:
Insert: 1165.6 ms
Delete: 4659.8 ms
Sum: 44.6 us
Random Index: 1225.2 us
= 7050.6446 ms

List:
Insert: 2.2 ms
Delete: 1.2 ms
Sum: 527 us
Random Index: 14750.7 ms
= 14.478,997 ms
*/

Container_t generate_container()
{
    static auto gen = std::mt19937{0};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-100, 100};

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

void indexing(std::vector<std::int32_t> &c)
{
    static auto gen = std::mt19937{0};
    static auto dist = std::uniform_int_distribution<std::size_t>{0, ELEMENTS};

    auto index = std::size_t{0};
    for (std::size_t i = 0; i < ELEMENTS; ++i)
    {
        index = dist(gen);
        c[index] = 42;
    }
}

void indexing(std::list<std::int32_t> &c)
{
    static auto gen = std::mt19937{0};
    static auto dist = std::uniform_int_distribution<std::size_t>{0, ELEMENTS};

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

int main()
{
#ifdef USING_VEC
    std::cout << "Vector:\n";
#else
    std::cout << "List:\n";
#endif
    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            auto c = generate_container();
            const auto t = cpptiming::Timer{};
            insertion(c);
            total_time += t.elapsed_time<cpptiming::millisecs, double>();
        }

        std::cout << "Insert: " << total_time / NUM_RUNS << " ms" << '\n';
    }

    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            auto c = generate_container();
            const auto t = cpptiming::Timer{};
            deletion(c);
            total_time += t.elapsed_time<cpptiming::millisecs, double>();
        }

        std::cout << "Delete: " << total_time / NUM_RUNS << " ms" << '\n';
    }

    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            auto c = generate_container();
            const auto t = cpptiming::Timer{};
            summing(c);
            total_time += t.elapsed_time<cpptiming::microsecs, double>();
        }

        std::cout << "Sum: " << total_time / NUM_RUNS << " us" << '\n';
    }

    {
        auto total_time = double{0.0};

        for (std::size_t run = 0; run < NUM_RUNS; run++)
        {
            auto c = generate_container();
            cpptiming::Timer t;
            indexing(c);
            total_time += t.elapsed_time<cpptiming::microsecs, double>();
        }

        std::cout << "Random Index: " << total_time / NUM_RUNS << " us" << '\n';
    }

    return 0;
}
