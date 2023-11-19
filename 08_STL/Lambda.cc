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

bool check_even(const int value)
{
    return (value % 2) == 0;
}

int main()
{
    auto my_vector = std::vector<int>(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);

    // transform
    auto my_result1 = std::vector<int>(10, 0);
    std::transform(my_vector.begin(),
                   my_vector.end(),
                   my_result1.begin(),
                   check_even);
    print_vector(my_result1);

    auto filter_even = [](const auto value) { return (value % 2) == 0; };

    auto my_result2 = std::vector<int>(10, 0);
    std::transform(my_vector.begin(),
                   my_vector.end(),
                   my_result2.begin(),
                   filter_even);
    print_vector(my_result2);

    // copy_if
    auto my_result3 = std::vector<int>{};
    std::copy_if(my_vector.begin(),
                 my_vector.end(),
                 std::back_inserter(my_result3),
                 filter_even);
    print_vector(my_result3);

    return 0;
}
