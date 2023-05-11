#include <chrono>
#include <cstdint>
#include <execution>
#include <iostream>
#include <random>
#include <vector>

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

struct Data
{
    std::int32_t v1;
    std::int32_t v2;
};

bool comp(const Data &i, Data &j)
{
    return i.v1 < j.v1 && i.v2 < j.v2;
}

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);
    std::generate(my_vector.begin(), my_vector.end(), gen);
    print_vector(my_vector);
    auto my_vector2 = my_vector;

    const auto min = std::min_element(my_vector.begin(), my_vector.end());
    const auto max = std::max_element(my_vector.begin(), my_vector.end());
    std::cout << "Min: " << *min << " Max: " << *max << '\n';

    const auto eq = std::equal(std::execution::par,
                               my_vector.begin(),
                               my_vector.end(),
                               my_vector2.begin());
    std::cout << "Equal? " << std::boolalpha << eq << '\n';

    return 0;
}
