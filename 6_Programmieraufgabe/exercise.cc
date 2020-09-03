#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

#include "exercise.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

// Aufgabe 2
string get_oldest_friend(const Friends &friends)
{
	string oldest_friend = "";
	int oldest_age = 0;

	for (const auto &val : friends)
	{
		pair<int, int> p = val.second;

		if (p.first > oldest_age)
		{
			oldest_age = p.first;
			oldest_friend = val.first;
		}
	}

	return oldest_friend;
}

string get_heaviest_friend(const Friends &friends)
{
	string heaviest_friend = "";
	int heaviest_weight = 0;

	for (const auto &val : friends)
	{
		pair<int, int> p = val.second;

		if (p.second > heaviest_weight)
		{
			heaviest_weight = p.second;
			heaviest_friend = val.first;
		}
	}

	return heaviest_friend;
}