#pragma once

#include <cstdint>

constexpr static std::uint32_t LEN_X = 10U;
constexpr static std::uint32_t START = 0U;
constexpr static std::uint32_t GOAL = 9U;
constexpr static char LEFT = 'a';
constexpr static char RIGHT = 'd';

void game();
