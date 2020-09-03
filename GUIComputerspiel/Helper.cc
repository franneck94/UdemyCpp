#include <QDateTime>
#include <random>


#include "Helper.h"

UInt random_uint(const UInt &lbound, const UInt &ubound)
{
    unsigned int ms = static_cast<unsigned int>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<UInt> dist(lbound, ubound);
    return dist(gen);
}

Position random_position(const UInt &lbound1, const UInt &ubound1, const UInt &lbound2, const UInt &ubound2)
{
    Position pos(random_uint(lbound1, ubound1), random_uint(lbound2, ubound2));
    return pos;
}
