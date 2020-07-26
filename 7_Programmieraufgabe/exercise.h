#ifndef EXERCISE_H
#define EXERCISE_H

#include <vector>
using std::vector;

typedef vector<bool> BinaryArray;

// Aufgabe 2
vector<bool> shuffle_till_equal(const BinaryArray &target, BinaryArray input);

// Aufgabe 3
vector<bool> smart_shuffle_till_equal(const BinaryArray &target, BinaryArray input);

#endif // _EXERCISE_H