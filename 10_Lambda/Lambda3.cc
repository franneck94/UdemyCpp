#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void print_vector(const std::vector<int> &vec)
{
    for (const auto &val : vec)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    print_vector(my_vector);

    // replace_if

    const int replace_value = 42;
    const int check_value = 2;

    std::replace_if(
        my_vector.begin(),
        my_vector.end(),
        [&](const int val) { return val == check_value; },
        replace_value);

    print_vector(my_vector);

    // sort

    auto sorting = [](const int val1, const int val2) { return val1 > val2; };

    std::sort(my_vector.begin(), my_vector.end(), sorting);

    print_vector(my_vector);

    // sort: generic lambda

    auto sorting2 = [](const auto val1, const auto val2) { return val1 < val2; };

    std::sort(my_vector.begin(), my_vector.end(), sorting2);

    print_vector(my_vector);

    return 0;
}
