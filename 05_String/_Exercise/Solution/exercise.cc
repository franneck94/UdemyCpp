#include <cstdint>
#include <iostream>

#include "exercise.h"

// Exercise 1
std::uint8_t hex_xor(const std::uint8_t hex1, const std::uint8_t hex2)
{
    return (hex1 ^ hex2);
}

// Exercise 2
ByteArray hex_vector_xor(const ByteArray &vec1, const ByteArray &vec2)
{
    auto result = ByteArray(vec1.size(), 0x00);

    for (std::size_t i = 0; i < vec1.size(); ++i)
    {
        result[i] = hex_xor(vec1[i], vec2[i]);
    }

    return result;
}
