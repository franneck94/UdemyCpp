#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../Array.h"

TEST_CASE("array_test_element_access")
{
    learncpp::array<int, 3> arr{1, 2, 3};
    REQUIRE_THROWS_AS(arr.at(-1), std::out_of_range);
    REQUIRE(1 == arr.at(0));
    REQUIRE(2 == arr.at(1));
    REQUIRE(3 == arr.at(2));
    REQUIRE_THROWS_AS(arr.at(3), std::out_of_range);

    REQUIRE(1 == arr[0]);
    REQUIRE(2 == arr[1]);
    REQUIRE(3 == arr[2]);

    REQUIRE(1 == arr.front());
    REQUIRE(3 == arr.back());

    int* data = arr.data();
    REQUIRE(1 == data[0]);
    REQUIRE(2 == data[1]);
    REQUIRE(3 == data[2]);
}

TEST_CASE("array_test_iterators")
{
    learncpp::array<int, 3> arr{1, 2, 3};

    int i = 1;
    for(const auto& val : arr)
    {
        REQUIRE(i == val);
        ++i;
    }
}

TEST_CASE("array_test_capacity")
{
    learncpp::array<int, 3> arr{1, 2, 3};

    REQUIRE(3 == arr.size());
    REQUIRE(false == arr.empty());
}

TEST_CASE("array_test_modifiers")
{
    learncpp::array<int, 3> arr{1, 2, 3};
    arr.fill(42);

    REQUIRE(42 == arr[0]);
    REQUIRE(42 == arr[1]);
    REQUIRE(42 == arr[2]);
}