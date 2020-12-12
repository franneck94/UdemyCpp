#pragma once

#include <vector>

typedef unsigned char uchar;
typedef std::vector<uchar> ByteArray;

// Aufgabe 1
uchar hex_xor(uchar &hex1, uchar &hex2);

// Aufgabe 2
ByteArray hex_vector_xor(ByteArray &vec1, ByteArray &vec2);

