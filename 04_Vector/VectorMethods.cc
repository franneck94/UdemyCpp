#include <iostream>
#include <vector>

void print_vector_info(const std::vector<int> &my_vector)
{
    std::cout << "Size: " << my_vector.size() << std::endl;
    std::cout << "Capacity: " << my_vector.capacity() << std::endl;
    std::cout << "Empty?: " << std::boolalpha << my_vector.empty() << std::endl
              << std::endl;
}

int main()
{
    std::vector<int> my_vector(10, 0);

    print_vector_info(my_vector);

    my_vector.reserve(13);

    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);

    print_vector_info(my_vector);

    my_vector.push_back(4);
    my_vector.shrink_to_fit();

    print_vector_info(my_vector);

    my_vector.clear();

    print_vector_info(my_vector);

    return 0;
}
