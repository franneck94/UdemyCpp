#pragma once

#include <vector>

using BinaryArray = std::vector<bool>;

// Exercise 2
std::vector<bool> shuffle_till_equal(const BinaryArray &target,
                                     BinaryArray input);

// Exercise 3
std::vector<bool> smart_shuffle_till_equal(const BinaryArray &target,
                                           BinaryArray input);
