#ifndef EXERCISE_H
#define EXERCISE_H

#include <vector>
using std::vector;

typedef unsigned char uchar;
typedef vector<uchar> ByteArray;

// Aufgabe 1
uchar hex_xor(uchar &hex1, uchar &hex2);

// Aufgabe 2
ByteArray hex_vector_xor(ByteArray &vec1, ByteArray &vec2);

#endif // _EXERCISE_H
