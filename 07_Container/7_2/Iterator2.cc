#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
    auto my_vector = std::vector{0, 1, 2, 3, 4, 5};
    auto my_list = std::list{0, 1, 2, 3, 4, 5};

    auto vec_it = my_vector.begin();
    std::advance(vec_it, 2); // it += 2;
    auto list_it = my_list.begin();
    std::advance(list_it, 2); // it += 2;

    std::cout << "Vector[2] = " << *vec_it << '\n';
    std::cout << "List[2] = " << *list_it << '\n';

    auto dist1 = std::distance(vec_it, my_vector.end());
    auto dist2 = std::distance(my_vector.begin(), vec_it);
    std::cout << dist1 << " " << dist2 << '\n';

    auto prev = std::prev(vec_it);
    std::cout << *prev << '\n';
    auto next = std::next(vec_it);
    std::cout << *next << '\n';

    return 0;
}
