#ifndef EXERCISE_H
#define EXERCISE_H

#include <utility>
#include <map>
#include <string>

using std::map;
using std::pair;
using std::string;

// Aufgabe 1
typedef map<string, pair<int, int>> Friends;

// Aufgabe  2
string get_oldest_friend(const Friends &friends);

string get_heaviest_friend(const Friends &friends);

#endif // _EXERCISE_H
