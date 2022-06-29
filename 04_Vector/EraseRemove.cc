#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void print_vector(const std::vector<int> &my_vector)
{
    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << "Vec[" << i << "] = " << my_vector[i] << std::endl;
    }
    std::cout << std::endl;
}

void print_vector_info(const std::vector<int> &my_vector)
{
    std::cout << "Size: " << my_vector.size() << std::endl;
    std::cout << "Capacity: " << my_vector.capacity() << std::endl;
    std::cout << "Empty?: " << std::boolalpha << my_vector.empty() << std::endl
              << std::endl;
}

bool is_odd(const int i)
{
    return i % 2;
}

int main()
{
    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);

    // std::vector<int>::iterator it = std::remove(my_vector.begin(), my_vector.end(), 2);
    // std::cout << *it << std::endl;
    // print_vector(my_vector);

    my_vector.erase(std::remove(my_vector.begin(), my_vector.end(), 2), my_vector.end());
    print_vector(my_vector);

    my_vector.erase(std::remove_if(my_vector.begin(), my_vector.end(), is_odd),
                    my_vector.end());
    print_vector(my_vector);

    return 0;
}
