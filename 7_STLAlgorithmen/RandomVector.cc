#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

void random_vector(std::vector<int> &vec)
{
    std::random_device seed_generator;
    std::mt19937 random_generator(seed_generator());
    std::uniform_int_distribution<int> random_distribution(-10, 10);

    for (auto &val : vec)
    {
        val = random_distribution(random_generator);
    }
}

int main()
{
    // Erstelle eine Funktion, die einen int-Vector als Referenz entgegen nimmt und
    // diesen mit zufälligen Werten aus dem Intervall [-10, 10] befüllt.
    std::vector<int> vector_a(10, 0);

    random_vector(vector_a);

    for (auto &val : vector_a)
    {
        std::cout << val << std::endl;
    }

    return 0;
}
