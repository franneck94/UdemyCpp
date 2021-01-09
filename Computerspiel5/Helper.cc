#include <random>

#include "Helper.h"

unsigned int random_uint(const unsigned int lower,
                         const unsigned int upper)
{
    std::random_device gen;
    std::uniform_int_distribution<unsigned int> dist(lower, upper);

    return dist(gen);
}

Position random_position(const unsigned int lower_x,
                         const unsigned int upper_x,
                         const unsigned int lower_y,
                         const unsigned int upper_y)
{
    Position pos(random_uint(lower_x, upper_x), random_uint(lower_y, upper_y));

    return pos;
}
