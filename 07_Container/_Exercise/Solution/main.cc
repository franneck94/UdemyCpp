#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>

#include "exercise.h"

int main()
{
    // Exercise 1
    auto friends = Friends{};

    friends["Jan"] = std::make_pair(23, 68);
    friends["Dennis"] = std::make_pair(27, 75);
    friends["Peter"] = std::make_pair(54, 70);
    friends["Kathrin"] = std::make_pair(30, 60);
    friends["Lisa"] = std::make_pair(26, 65);

    // Exercise 2
    const auto oldest_friend = get_oldest_friend(friends);
    const auto heaviest_friend = get_heaviest_friend(friends);

    std::cout << "My oldest friend: " << oldest_friend << '\n';
    std::cout << "My heaviest friend: " << heaviest_friend << '\n';

    return 0;
}
