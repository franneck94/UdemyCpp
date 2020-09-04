#ifndef EXERCISE_H
#define EXERCISE_H

#include <vector>

typedef std::vector<bool> BinaryArray;

// Aufgabe 2
std::vector<bool> shuffle_till_equal(const BinaryArray &target, BinaryArray input);

// Aufgabe 3
std::vector<bool> smart_shuffle_till_equal(const BinaryArray &target, BinaryArray input);

#endif // _EXERCISE_H