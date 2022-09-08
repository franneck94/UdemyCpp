#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using ClockType = std::chrono::steady_clock;
using ClockRes = std::chrono::microseconds;

constexpr static auto NUM_ELEMENTS = 10U;

std::int32_t gen()
{
    static auto seed = std::random_device{};
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    return dist(gen);
}

void print_vector(const std::vector<std::int32_t> &vec)
{
    for (const auto v : vec)
    {
        std::cout << v << '\n';
    }
    std::cout << '\n';
}

bool func1(const std::int32_t val)
{
    return (val > -5) && (val < 5);
}

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);
    std::generate(my_vector.begin(), my_vector.end(), gen);
    print_vector(my_vector);

    const auto check1 = std::all_of(my_vector.begin(), my_vector.end(), func1);
    const auto check2 = std::any_of(my_vector.begin(), my_vector.end(), func1);
    const auto check3 = std::none_of(my_vector.begin(), my_vector.end(), func1);

    std::cout << std::boolalpha << check1 << '\n';
    std::cout << std::boolalpha << check2 << '\n';
    std::cout << std::boolalpha << check3 << '\n';

    return 0;
}
