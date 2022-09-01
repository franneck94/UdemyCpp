#include <iostream>
#include <list>
#include <vector>

int main()
{
    const auto vec = std::vector<int>{1, 2, 3};
    const auto lst = std::list<int>{1, 2, 3};

    std::cout << vec.size() << '\n';
    std::cout << lst.size() << '\n';

    std::cout << vec.empty() << '\n';
    std::cout << lst.empty() << '\n';

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    for (const auto val : vec)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    for (const auto val : lst)
    {
        std::cout << val << ' ';
    }

    for (std::size_t i = 0; i < 3; ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
    auto it_lst = lst.begin();
    for (std::size_t i = 0; i < 3; ++i)
    {
        std::cout << *it_lst << ' ';
        ++it_lst;
    }

    return 0;
}
