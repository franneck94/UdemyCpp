#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    std::vector<int> my_result(10, 0);
    std::vector<int> my_result2;

    // REPLACE IF: Alle Val Werte die gleich 2 sind, sollen mit dem Wert 42 ersetzt werden
    std::replace_if(
        my_vector.begin(), my_vector.end(), [](const auto &val) { return val == 2; }, 42);
    for (const auto &val : my_vector)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    // SORTING
    auto sorting = [](const auto &val1, const auto &val2) { return val1 > val2; };
    std::sort(my_vector.begin(), my_vector.end(), sorting);
    for (const auto &val : my_vector)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    return 0;
}