#include <algorithm>
#include <iostream>
#include <vector>

void print_vector(const std::vector<int> &my_vector)
{
    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        std::cout << my_vector[i] << std::endl;
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

bool is_negative(const int val)
{
    return val < 0;
}

int main()
{
    auto my_vector = std::vector<int>{-1, 20, -33, 14, 35};
    print_vector(my_vector);
    print_vector_info(my_vector);

    auto remove_it1 = std::remove(my_vector.begin(), my_vector.end(), -1);
    my_vector.erase(remove_it1, my_vector.end());
    print_vector(my_vector);

    auto remove_it2 = std::remove_if(my_vector.begin(), my_vector.end(), is_negative);
    my_vector.erase(remove_it2, my_vector.end());
    print_vector(my_vector);

    return 0;
}
