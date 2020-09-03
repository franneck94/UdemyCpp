#include <iostream>

int main()
{
	// C-style char arrays: \0 (null-terminating character)
	std::cout << "Hello World!" << std::endl;

	char str[] = "Jan Schaffranek";
	std::cout << str << std::endl;

	for (int i = 0; i < 15; i++)
	{
		std::cout << str[i] << std::endl;
	}

	return 0;
}