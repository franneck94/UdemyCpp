#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <utility>
#include "../Pair.h"

TEST_CASE("pair_test_same_types")
{
    // Default constructor
    learncpp::pair<int, double> pair1{10, 42.0};
    REQUIRE(10 == pair1.first);
    REQUIRE(42.0 == pair1.second);

    // Copy constructor
    learncpp::pair<int, double> pair2 = pair1;
    REQUIRE(10 == pair2.first);
    REQUIRE(42.0 == pair2.second);

    // Move constructor
    learncpp::pair<int, double> pair3(learncpp::pair<int, double>(1, 2.0));
    REQUIRE(10 == pair2.first);
    REQUIRE(42.0 == pair2.second);

    // Copy assignment operator
    pair2 = pair3;
    REQUIRE(1 == pair2.first);
    REQUIRE(2.0 == pair2.second);

    // Move assignment operator
    pair3 = std::move(pair1);
    REQUIRE(10 == pair3.first);
    REQUIRE(42.0 == pair3.second);
}

TEST_CASE("pair_test_convertible_types")
{
    learncpp::pair<int, double> pair1{10, 42.0};
    REQUIRE(10 == pair1.first);
    REQUIRE(42.0 == pair1.second);

    // Copy constructor of  different type
    learncpp::pair<short, float> pair2 = pair1;
    REQUIRE(10 == pair2.first);
    REQUIRE(42.0 == pair2.second);

    // Move constructor of  different type
    learncpp::pair<short, float> pair3(learncpp::pair<int, double>(-10, -42.0));
    REQUIRE(-10 == pair3.first);
    REQUIRE(-42.0 == pair3.second);

    // Copy assignment operator
    pair2 = pair3;
    REQUIRE(-10 == pair2.first);
    REQUIRE(-42.0 == pair2.second);

    // Move assignment operator
    pair3 = std::move(pair1);
    REQUIRE(10 == pair3.first);
    REQUIRE(42.0 == pair3.second);
}