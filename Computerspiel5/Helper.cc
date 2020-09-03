#include <random>

#include "Helper.h"

UInt random_uint(const UInt &lbound, const UInt &ubound)
{
    std::random_device gen;
    std::uniform_int_distribution<UInt> dist(lbound, ubound);
    return dist(gen);
}

Position random_position(const UInt &lbound1, const UInt &ubound1, const UInt &lbound2, const UInt &ubound2)
{
    Position pos(random_uint(lbound1, ubound1), random_uint(lbound2, ubound2));
    return pos;
}