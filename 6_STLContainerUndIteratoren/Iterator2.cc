#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> my_vector(5, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    std::list<int> my_list(5, 0);
    std::iota(my_list.begin(), my_list.end(), 0);

    auto it = my_list.begin();

    std::advance(it, 2); // it += 2;

    std::cout << "Vector[2] = " << my_vector[2] << std::endl;
    std::cout << "List[2] = " << *it << std::endl;

    auto dist = std::distance(it, my_list.end());
    std::cout << "Distance = " << dist << std::endl;

    auto prev = std::prev(it);
    auto next = std::next(it);

    std::cout << "Prev = " << *prev << std::endl;
    std::cout << "Next = " << *next << std::endl;

    return 0;
}
