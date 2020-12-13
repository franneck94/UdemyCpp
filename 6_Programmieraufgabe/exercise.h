#pragma once

#include <utility>
#include <map>
#include <string>

// Aufgabe 1
typedef std::map<std::string, std::pair<int, int>> Friends;

// Aufgabe  2
std::string get_oldest_friend(const Friends &friends);

std::string get_heaviest_friend(const Friends &friends);
