#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    std::vector<int>::iterator it = my_vector.begin();
    auto it2 = my_vector.begin();

    // [begin, end)
    for (auto it3 = my_vector.begin(); it3 != my_vector.end(); ++it3)
    {
        std::cout << *it3 << std::endl;
    }

    // For-each based loop
    for (auto &val : my_vector)
    {
        std::cout << val << std::endl;
    }

    return 0;
}
