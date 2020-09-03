#include <iostream>

int main()
{
	int number;
	int abs; // absolute

	std::cin >> number;

	if (number < 0)
	{
		abs = number * (-1);
	}
	else // (number >= 0)
	{
		abs = number;
	}

	std::cout << "Der Betrag von: " << number << " ist: " << abs << std::endl;

	return 0;
}