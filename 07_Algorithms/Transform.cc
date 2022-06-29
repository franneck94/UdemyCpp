#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

int increment(int i)
{
    return ++i;
}

int add(int i, int j)
{
    return i + j;
}

void print_vector(const std::vector<int> &my_vector)
{
    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << "Vec[" << i << "] = " << my_vector[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> my_vector1(10, 0);
    std::vector<int> my_vector2(10, 0);
    std::vector<int> my_vector3(10, 0);

    std::iota(my_vector1.begin(), my_vector1.end(), 0);
    print_vector(my_vector1);

    std::transform(my_vector1.begin(), my_vector1.end(), my_vector2.begin(), increment);
    print_vector(my_vector2);

    std::transform(my_vector1.begin(),
                   my_vector1.end(),
                   my_vector2.begin(),
                   my_vector3.begin(),
                   add);
    print_vector(my_vector3);

    return 0;
}
