#include <QDateTime>
#include <random>


#include "Helper.h"

unsigned int random_uint(const unsigned int &lbound, const unsigned int &ubound)
{
    unsigned int ms = static_cast<unsigned int>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<unsigned int> dist(lbound, ubound);
    return dist(gen);
}

Position random_position(const unsigned int &lbound1, const unsigned int &ubound1, const unsigned int &lbound2, const unsigned int &ubound2)
{
    Position pos(random_uint(lbound1, ubound1), random_uint(lbound2, ubound2));
    return pos;
}
