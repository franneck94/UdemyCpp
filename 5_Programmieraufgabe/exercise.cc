#include <iostream>

#include "exercise.h"

// Exercise 1
uchar hex_xor(uchar &hex1, uchar &hex2)
{
    return (hex1 ^ hex2);
}

// Exercise 2
ByteArray hex_vector_xor(ByteArray &vec1, ByteArray &vec2)
{
    std::vector<uchar> result(vec1.size(), 0x00);

    for (std::size_t i = 0; i < vec1.size(); ++i)
    {
        result[i] = hex_xor(vec1[i], vec2[i]);
    }

    return result;
}
