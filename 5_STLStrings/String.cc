#include <iostream>
#include <string>
#include <fstream>

using std::string;

int main()
{
	string s = "Hallo das ist ein Text";

	size_t index = s.find("Hallo");

	if (index != string::npos)
	{
		std::cout << std::endl
				  << index;
	}
	else
	{
		std::cout << std::endl
				  << "Nicht enthalten!";
	}

	std::cout << std::endl
			  << s;

	return 0;
}