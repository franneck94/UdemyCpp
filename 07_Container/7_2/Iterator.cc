#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    auto my_vector = std::vector{0, 1, 2, 3, 4, 5};

    // ForwardIterator
    auto it1 = my_vector.begin();
    auto it2 = my_vector.end();

    for (; it1 != it2; ++it1)
    {
        *it1 = 1;
    }

    // BidirectionalIterator
    auto it3 = my_vector.rbegin();
    auto it4 = my_vector.rend();

    for (; it3 != it4; ++it3)
    {
        *it3 = 2;
    }

    // Const ForwardIterator
    auto it5 = my_vector.cbegin();
    auto it6 = my_vector.cend();

    // for (; it5 != it6; ++it5)
    // {
    //     *it5 = 1;
    // }

    // Const BidirectionalIterator
    auto it7 = my_vector.crbegin();
    auto it8 = my_vector.crend();

    // for (; it7 != it8; ++it7)
    // {
    //     *it7 = 2;
    // }

    return 0;
}
