#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void print_vector(const std::vector<int> &vec)
{
    for (const auto &val : vec)
    {
        std::cout << val << '\n';
    }

    std::cout << '\n';
}

int main()
{
    auto my_vector = std::vector<int>(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);

    my_vector.erase(std::remove_if(my_vector.begin(),
                                   my_vector.end(),
                                   [](const auto value) { return value > 5; }),
                    my_vector.end());
    print_vector(my_vector);

    // =: copy
    // &: reference
    const auto upper_bound = 3;
    my_vector.erase(
        std::remove_if(my_vector.begin(),
                       my_vector.end(),
                       [=](const auto value) { return value > upper_bound; }),
        my_vector.end());
    print_vector(my_vector);


    return 0;
}
