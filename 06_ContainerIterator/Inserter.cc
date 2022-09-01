#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    auto my_vector = std::vector<int>(5, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    auto my_vector2 = std::vector<int>(5, 0);
    std::iota(my_vector2.begin(), my_vector2.end(), 5);

    auto my_vector3 = std::vector<int>{};

    // Inserter (Container needs the insert method)
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::inserter(my_vector3, my_vector3.end()));

    std::copy(my_vector2.begin(),
              my_vector2.end(),
              std::inserter(my_vector3, my_vector3.begin() + 1));

    std::cout << "Inserter: \n";
    for (const auto &val : my_vector3)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    auto my_vector4 = std::vector<int>{};

    // Back Inserter (Container needs the push_back method)
    std::copy(my_vector.begin(), my_vector.end(), std::back_inserter(my_vector4));

    std::copy(my_vector2.begin(), my_vector2.end(), std::back_inserter(my_vector4));

    std::cout << "Back Inserter: \n";
    for (const auto &val : my_vector4)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    // Front Inserter (Container needs the push_front method)
    auto my_list = std::list<int>(my_vector.begin(), my_vector.end());
    auto my_list2 = std::list<int>(my_vector2.begin(), my_vector2.end());
    auto my_list3 = std::list<int>{};

    std::copy(my_list.begin(), my_list.end(), std::front_inserter(my_list3));

    std::copy(my_list2.begin(), my_list2.end(), std::front_inserter(my_list3));

    std::cout << "Front Inserter: \n";
    for (const auto &val : my_list3)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
