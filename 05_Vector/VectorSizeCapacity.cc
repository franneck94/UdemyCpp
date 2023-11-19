#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    auto my_vector = std::vector<std::int32_t>{};

    for (int i = 0; i < 9; i++)
    {
        my_vector.push_back(i);
    }

    std::cout << "Size: " << my_vector.size() << '\n';
    std::cout << "Capacity: " << my_vector.capacity() << '\n';

    my_vector.push_back(10);

    std::cout << "Size: " << my_vector.size() << '\n';
    std::cout << "Capacity: " << my_vector.capacity() << '\n';

    return 0;
}
