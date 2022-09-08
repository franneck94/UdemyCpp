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
    auto gen = std::random_device{};
    auto dist = std::bernoulli_distribution(0.5);

    auto target = BinaryArray(20, false);
    std::generate(target.begin(), target.end(), [&] { return dist(gen); });

    auto input = BinaryArray(target.begin(), target.end());
    std::shuffle(input.begin(), input.end(), std::default_random_engine(42));

    for (std::size_t i = 0; i < target.size(); ++i)
    {
        std::cout << "Target[" << i << "] = " << target[i] << std::endl;
    }
    for (std::size_t i = 0; i < input.size(); ++i)
    {
        std::cout << "Input[" << i << "] = " << input[i] << std::endl;
    }

    ////// START EXERCISES

    // Exercise 1
    std::cout << std::endl << "Starting exercise 1";
    auto start = std::chrono::high_resolution_clock::now();
    const auto result_exercise1 = shuffle_till_equal(target, input);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_milliseconds =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() /
        1000.0;
    std::cout << std::endl << "Time for exercise 1 in ms: " << elapsed_milliseconds;
    const auto is_equal2 =
        std::equal(result_exercise1.begin(), result_exercise1.end(), target.begin());
    std::cout << std::endl << "Vectors are equal: " << is_equal2 << std::endl;

    // Exercise 2
    std::cout << std::endl << "Starting exercise 2";
    start = std::chrono::high_resolution_clock::now();
    const auto result_exercise2 = smart_shuffle_till_equal(target, input);
    end = std::chrono::high_resolution_clock::now();
    elapsed_milliseconds =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() /
        1000.0;
    std::cout << std::endl << "Time for exercise 2 in ms: " << elapsed_milliseconds;
    const auto is_equal3 =
        std::equal(result_exercise2.begin(), result_exercise2.end(), target.begin());
    std::cout << std::endl << "Vectors are equal: " << is_equal3 << std::endl;

    return 0;
}
