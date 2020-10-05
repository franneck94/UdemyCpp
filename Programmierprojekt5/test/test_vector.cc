#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../Vector.h"
#include "../Algorithm.h"

TEST_CASE("vector_test_element_access")
{
    learncpp::vector<int> vec{1, 2, 3};
    REQUIRE_THROWS_AS(vec.at(-1), std::out_of_range);
    REQUIRE(1 == vec.at(0));
    REQUIRE(2 == vec.at(1));
    REQUIRE(3 == vec.at(2));
    REQUIRE_THROWS_AS(vec.at(3), std::out_of_range);

    REQUIRE(1 == vec[0]);
    REQUIRE(2 == vec[1]);
    REQUIRE(3 == vec[2]);

    REQUIRE(1 == vec.front());
    REQUIRE(3 == vec.back());

    int* data = vec.data();
    REQUIRE(1 == data[0]);
    REQUIRE(2 == data[1]);
    REQUIRE(3 == data[2]);
}

TEST_CASE("vector_test_iterators")
{
    learncpp::vector<int> vec{1, 2, 3};

    int i = 1;
    for(const auto& val : vec)
    {
        REQUIRE(i == val);
        ++i;
    }

    REQUIRE(vec.begin() != vec.end());
    vec.clear();
    REQUIRE(vec.begin() == vec.end());

    vec.shrink_to_fit();
    REQUIRE(vec.begin() == vec.end());

    vec.push_back(1);
    REQUIRE(vec.begin() != vec.end());
}

TEST_CASE("vector_test_capacity")
{
    learncpp::vector<int> vec{1, 2, 3};
    REQUIRE(3 == vec.size());
    REQUIRE(3 == vec.capacity());

    vec.clear();
    REQUIRE(0 == vec.size());
    REQUIRE(3 == vec.capacity());

    vec.shrink_to_fit();
    REQUIRE(0 == vec.size());
    REQUIRE(0 == vec.capacity());
}

/**
 * @brief Test PushBack and PopBack
 * 
 */
TEST_CASE("vector_test_modifiers1")
{
    learncpp::vector<int> vec;
    REQUIRE(0 == vec.size());
    REQUIRE(0 == vec.capacity());

    vec.push_back(1);
    REQUIRE(1 == vec.size());
    REQUIRE(1 == vec.capacity());

    vec.pop_back();
    REQUIRE(0 == vec.size());
    REQUIRE(1 == vec.capacity());

    int val = 42;
    vec.push_back(val);
    REQUIRE(1 == vec.size());
    REQUIRE(1 == vec.capacity());
    REQUIRE(42 == vec[0]);

    vec.resize(2);
    REQUIRE(2 == vec.size());
    REQUIRE(2 == vec.capacity());
    REQUIRE(42 == vec[0]);
    REQUIRE(0 == vec[1]);
}

/**
 * @brief Test: Emplace, EmplaceBack, Insert
 * 
 */
TEST_CASE("vector_test_modifiers2")
{
    learncpp::vector<int> vec;
    
}

TEST_CASE("vector_test_algorithms")
{
    learncpp::vector<double> vec{1, 2, 3};

    REQUIRE(6.0 == learncpp::sum(vec));
    REQUIRE(2.0 == learncpp::mean(vec));
    Approx target_variance = Approx(0.6666666666666666).epsilon(1e-6);
    REQUIRE(target_variance == learncpp::variance(vec));
    Approx target_std = Approx(0.816496580927726).epsilon(1e-6);
    REQUIRE(target_std == learncpp::stddev(vec));
}