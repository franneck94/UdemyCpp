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

int main()
{
    auto my_vector = std::vector<std::int32_t>{1, 2, 3, 4, 5};
    print_vector(my_vector);
    print_vector_info(my_vector);

    auto p = my_vector.data();
    std::cout << *p << '\n';
    p += 2;
    std::cout << *p << '\n' << '\n';

    auto &f = my_vector.front();
    std::cout << f << '\n';
    f = -1;
    std::cout << f << '\n';
    std::cout << my_vector[0] << '\n' << '\n';

    auto &b = my_vector.back();
    std::cout << b << '\n';
    b = -5;
    std::cout << b << '\n';
    std::cout << my_vector[my_vector.size() - 1] << '\n' << '\n';

    // [begin, end)
    auto begin = my_vector.begin();
    auto end = my_vector.end();
    std::cout << *begin << '\n';
    std::cout << *end << '\n' << '\n';

    ++begin;
    --end;
    std::cout << *begin << '\n';
    std::cout << *end << '\n' << '\n';

    for (auto it = my_vector.begin(); it != my_vector.end(); ++it)
    {
        std::cout << *it << '\n';
    }

    return 0;
}
