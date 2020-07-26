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

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::tuple;
using std::map;

int main()
{
	// Aufgabe 1
	Friends friends;

	friends["Jan"] = pair<int, int>(23, 68);
	friends["Dennis"] = pair<int, int>(27, 75);
	friends["Peter"] = pair<int, int>(54, 70);
	friends["Kathrin"] = pair<int, int>(30, 60);
	friends["Lisa"] = pair<int, int>(26, 65);

	// Aufgabe 2
	string oldest_friend = get_oldest_friend(friends);
	string heaviest_friend = get_heaviest_friend(friends);

	cout << "My oldest friend: " << oldest_friend << endl;
	cout << "My heaviest friend: " << heaviest_friend << endl;

	return 0;
}