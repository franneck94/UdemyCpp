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

    // remove_if, erase

    my_vector.erase(std::remove_if(my_vector.begin(),
                                   my_vector.end(),
                                   [](const int val) {
                                       if (val > 5)
                                       {
                                           return true;
                                       }
                                       else
                                       {
                                           return false;
                                       }
                                   }),
                    my_vector.end());

    print_vector(my_vector);

    // remove_if, erase: capture variable
    int upper_bound = 3;

    my_vector.erase(std::remove_if(my_vector.begin(),
                                   my_vector.end(),
                                   [&upper_bound](const int val) {
                                       if (val > upper_bound)
                                       {
                                           return true;
                                       }
                                       else
                                       {
                                           return false;
                                       }
                                   }),
                    my_vector.end());

    print_vector(my_vector);

    return 0;
}
