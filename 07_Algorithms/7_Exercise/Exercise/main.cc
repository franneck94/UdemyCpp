#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "exercise.h"

int main()
{
    // Exercise 1
    std::random_device gen;
    std::bernoulli_distribution dist(0.5);

    BinaryArray target(20, false);
    // ...

    BinaryArray input(target.begin(), target.end());
    // ...

    for (std::size_t i = 0; i < target.size(); ++i)
    {
        std::cout << "Target[" << i << "] = " << target[i] << std::endl;
    }

    for (std::size_t i = 0; i < input.size(); ++i)
    {
        std::cout << "Input[" << i << "] = " << input[i] << std::endl;
    }

    // Exercise 2
    std::cout << std::endl << "Starting exercise 2";
    auto start = std::chrono::high_resolution_clock::now();
    BinaryArray result_exercise2 = shuffle_till_equal(target, input);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0;
    std::cout << std::endl << "Time for exercise 2 in ms: " << elapsed_milliseconds;
    bool is_equal2 = std::equal(result_exercise2.begin(), result_exercise2.end(), target.begin());
    std::cout << std::endl << "Vectors are equal: " << is_equal2 << std::endl;

    // Exercise 3
    std::cout << std::endl << "Starting exercise 3";
    start = std::chrono::high_resolution_clock::now();
    BinaryArray result_exercise3 = smart_shuffle_till_equal(target, input);
    end = std::chrono::high_resolution_clock::now();
    elapsed_milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0;
    std::cout << std::endl << "Time for exercise 3 in ms: " << elapsed_milliseconds;
    bool is_equal3 = std::equal(result_exercise3.begin(), result_exercise3.end(), target.begin());
    std::cout << std::endl << "Vectors are equal: " << is_equal3 << std::endl;

    return 0;
}
