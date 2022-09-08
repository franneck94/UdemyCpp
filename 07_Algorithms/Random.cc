#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

constexpr static auto NUM_ELEMENTS = 1'000'000U;

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);

    auto seed = std::random_device{};
    auto gen = std::mt19937{seed()};
    auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        my_vector[i] = dist(gen);
    }

    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << my_vector[i] << '\n';
    }

    return 0;
}
