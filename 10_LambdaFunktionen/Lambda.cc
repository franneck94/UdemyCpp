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

int check_even(const int val)
{
    if (val % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    print_vector(my_vector);

    // transform: element-wise operations with function object
    std::vector<int> my_result(10, 0);

    std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), check_even);

    print_vector(my_result);

    // transform: element-wise operations with lambda function
    std::vector<int> my_result2(10, 0);

    std::transform(my_vector.begin(), my_vector.end(), my_result2.begin(), [](const int val) -> int {
        if (val % 2 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    });

    print_vector(my_result2);

    // copy_if
    std::vector<int> my_result3;

    std::copy_if(my_vector.begin(), my_vector.end(), std::back_inserter(my_result3), [](const int val) -> int {
        if (val % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    print_vector(my_result3);

    return 0;
}
