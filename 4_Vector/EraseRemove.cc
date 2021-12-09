#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void print_vector(const std::vector<int> &vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << std::endl;
    }

    std::cout << std::endl;
}

bool is_odd(const int &i)
{
    return (i % 2);
}

int main()
{
    std::vector<int> my_vector(10, 0);

    std::iota(my_vector.begin(), my_vector.end(), 0.0);
    print_vector(my_vector);

    std::vector<int>::iterator start_erasing_it = std::remove(my_vector.begin(), my_vector.end(), 2);
    my_vector.erase(start_erasing_it, my_vector.end());
    print_vector(my_vector);

    my_vector.erase(std::remove_if(my_vector.begin(), my_vector.end(), is_odd), my_vector.end());
    print_vector(my_vector);

    return 0;
}
