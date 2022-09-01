#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    auto my_vector = std::vector<int>(5, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    auto it = my_vector.begin();
    std::advance(it, 2); // it += 2;

    std::cout << "Vector[2] = " << my_vector[2] << std::endl;
    std::cout << "List[2] = " << *it << std::endl;

    auto dist = std::distance(it, my_vector.end());
    std::cout << "Distance = " << dist << std::endl;

    auto prev = std::prev(it);
    auto next = std::next(it);

    std::cout << "Prev = " << *prev << std::endl;
    std::cout << "Next = " << *next << std::endl;

    return 0;
}
