#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <string_view>
#include <utility>

using Friends = std::map<std::string, std::pair<std::int32_t, std::int32_t>>;

std::string_view get_oldest_friend(const Friends &friends);

std::string_view get_heaviest_friend(const Friends &friends);
