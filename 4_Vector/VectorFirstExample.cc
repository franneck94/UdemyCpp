#include <iostream>
#include <vector>

int main()
{
    // int* data = new ...;
    //                         LEN,   DEFAULT_VALUE
    std::vector<int> my_vector(2, 42);

    std::cout << my_vector[0] << std::endl;
    std::cout << my_vector[1] << std::endl;

    my_vector[0] = 11;
    my_vector[1] = -43;

    std::cout << my_vector[0] << std::endl;
    std::cout << my_vector[1] << std::endl;
    //std::cout << my_vector[2] << std::endl;

    // At
    std::cout << my_vector.at(0) << std::endl;
    std::cout << my_vector.at(1) << std::endl;
    //std::cout << my_vector.at(2) << std::endl;

    // push_back
    my_vector.push_back(24); // 11, -43, 24

    // size
    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        std::cout << my_vector[i] << std::endl;
    }

    // pop_back
    my_vector.pop_back(); // 11, -43

    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        std::cout << my_vector[i] << std::endl;
    }

    return 0;
}
