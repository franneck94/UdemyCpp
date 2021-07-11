#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int increment(int i)
{
    return ++i;
}

int main()
{
    std::vector<int> vector_a(10, 3);
    std::vector<int> vector_b(10, 7);
    std::vector<int> vector_c(10, 0);

    std::transform(vector_a.begin(),
                   vector_a.end(),
                   vector_b.begin(),
                   vector_c.begin(),
                   std::plus<int>());

    for (const auto &val : vector_c)
    {
        std::cout << val << std::endl;
    }

    std::transform(vector_a.begin(),
                   vector_a.end(),
                   vector_b.begin(),
                   vector_a.begin(),
                   std::plus<int>());

    for (const auto &val : vector_a)
    {
        std::cout << val << std::endl;
    }

    std::transform(vector_a.begin(),
                   vector_a.end(),
                   vector_c.begin(),
                   increment);

    for (const auto &val : vector_c)
    {
        std::cout << val << std::endl;
    }

    return 0;
}
