#include <cstdint>
#include <iostream>
#include <string_view>

#include "exercise.h"

// Exercise 2
std::string_view get_oldest_friend(const Friends &friends)
{
    auto oldest_friend = std::string_view{};
    auto oldest_age = std::int32_t{};

    for (const auto &[key, val] : friends)
    {
        if (val.first > oldest_age)
        {
            oldest_age = val.first;
            oldest_friend = key;
        }
    }

    return oldest_friend;
}

std::string_view get_heaviest_friend(const Friends &friends)
{
    auto heaviest_friend = std::string_view{};
    auto heaviest_weight = std::int32_t{};

    for (const auto &[key, val] : friends)
    {
        if (val.second > heaviest_weight)
        {
            heaviest_weight = val.second;
            heaviest_friend = key;
        }
    }

    return heaviest_friend;
}
