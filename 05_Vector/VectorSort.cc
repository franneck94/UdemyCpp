#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void print_vector(const std::vector<std::int32_t> &my_vector)
{
    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        std::cout << my_vector[i] << '\n';
    }
    std::cout << '\n';
}


void print_vector_info(const std::vector<std::int32_t> &my_vector)
{
    std::cout << "Size: " << my_vector.size() << '\n';
    std::cout << "Capacity: " << my_vector.capacity() << '\n';
    std::cout << "Empty?: " << std::boolalpha << my_vector.empty() << "\n\n";
}

bool sort_ascending(const std::int32_t i, const std::int32_t j)
{
    return i < j;
}

bool sort_descending(const std::int32_t i, const std::int32_t j)
{
    return i > j;
}

bool sort_example(const std::int32_t i, const std::int32_t j)
{
    return i % 2 == 0 && j % 2 != 0;
}

int main()
{
    auto my_vector = std::vector<std::int32_t>{-1, 20, -33, 14, 35};
    print_vector(my_vector);
    print_vector_info(my_vector);

    std::sort(my_vector.begin(), my_vector.end(), sort_ascending);
    print_vector(my_vector);

    std::sort(my_vector.begin(), my_vector.end(), sort_descending);
    print_vector(my_vector);

    std::sort(my_vector.begin(), my_vector.end(), sort_example);
    print_vector(my_vector);

    return 0;
}
