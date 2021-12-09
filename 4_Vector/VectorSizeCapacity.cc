#include <iostream>
#include <vector>

int main()
{
    std::vector<int> my_vector;

    for (std::size_t i = 0; i < 14; ++i)
    {
        my_vector.push_back(i);
    }

    std::cout << my_vector.size() << std::endl;     // The currently used size of the underlying pointer array,
                                                    // size <= capacity
    std::cout << my_vector.capacity() << std::endl; // The real size of the underlying pointer array

    return 0;
}
