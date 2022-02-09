#include <iostream>
#include <vector>

int main()
{
    std::vector<int> my_vector(2, 0);

    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << my_vector[i] << std::endl;
    }
    std::cout << std::endl;

    my_vector[0] = 11;
    my_vector[1] = -42;

    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << my_vector[i] << std::endl;
    }
    std::cout << std::endl;

    my_vector.push_back(55);

    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << my_vector[i] << std::endl;
    }
    std::cout << std::endl;

    my_vector.pop_back();
    my_vector.pop_back();

    for (std::size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << my_vector[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
