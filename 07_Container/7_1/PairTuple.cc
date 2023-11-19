#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using UserData = std::pair<int, float>;

int main()
{
    auto my_pair = std::pair<int, float>{1337, -25.0F};
    std::cout << my_pair.first << '\n';
    std::cout << my_pair.second << '\n';

    auto my_tuple = std::tuple<int, float, std::string>{1337, -25.0F, "Peter"};
    std::cout << std::get<0>(my_tuple) << '\n';
    std::cout << std::get<1>(my_tuple) << '\n';
    std::cout << std::get<2>(my_tuple) << '\n';

    const auto data = std::vector<UserData>{{1337, -25.0F}, {10, 12.5F}};
    for (const auto &d : data)
    {
        std::cout << d.first << ' ' << d.second << '\n';
    }

    return 0;
}
