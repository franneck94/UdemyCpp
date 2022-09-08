#pragma once

#include <cstdint>
#include <vector>

using ByteArray = std::vector<std::uint8_t>;

// Exercise 1
std::uint8_t hex_xor(const std::uint8_t hex1, const std::uint8_t hex2);

// Exercise 2
ByteArray hex_vector_xor(const ByteArray &vec1, const ByteArray &vec2);
