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

    // ...

    // Exercise 2
    const auto oldest_friend = get_oldest_friend(friends);
    const auto heaviest_friend = get_heaviest_friend(friends);

    std::cout << "My oldest friend: " << oldest_friend << '\n';
    std::cout << "My heaviest friend: " << heaviest_friend << '\n';

    return 0;
}
