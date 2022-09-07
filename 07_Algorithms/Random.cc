#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

constexpr static auto NUM_ELEMENTS = 1'000'000U;

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0);

    auto seed_generator = std::random_device{};
    auto random_generator = std::mt19937_64{seed_generator()};
    auto random_distribution = std::uniform_int_distribution<std::int32_t>{-10, 10};

    for (std::size_t i = 0; i < NUM_ELEMENTS; i++)
    {
        my_vector[i] = random_distribution(random_generator);
    }

    // ....

    for (std::size_t i = 0; i < 10; i++)
    {
        std::cout << my_vector[i] << std::endl;
    }

    return 0;
}
