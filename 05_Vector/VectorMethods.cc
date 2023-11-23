#include <iostream>
#include <vector>

void print_vector_info(const std::vector<int> &my_vector)
{
    std::cout << "Vector Size: " << my_vector.size() << "\n";
    std::cout << "Vector Capacity: " << my_vector.capacity() << "\n";
    std::cout << "Vector Is Empty?: " << std::boolalpha << my_vector.empty()
              << "\n";
}

int main()
{
    const auto init_length = 10U;
    const auto init_value = 0;
    auto my_vector = std::vector<int>(init_length, init_value);

    print_vector_info(my_vector);

    my_vector.push_back(1);
    print_vector_info(my_vector);

    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);
    my_vector.push_back(4);
    my_vector.push_back(5);
    print_vector_info(my_vector);


    return 0;
}
