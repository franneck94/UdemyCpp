#include <iostream>
#include <string>
#include <vector>
#include <map>

using Id = int;

template <typename T>
using UserAccount = std::map<Id, std::vector<T>>;

//template <typename T>
//typedef std::map<Id, std::vector<T>> UserAccount;

int main()
{
	UserAccount<int> account_admins;
	UserAccount<int> account_users;

	return 0;
}