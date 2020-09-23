#include <iostream>
#include <string>

template <typename T, typename U>
T max(T &a, T &b, const U &c)
{
	std::cout << "C: " << c << std::endl;

	if (a < b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main()
{
	int a = 4;
	int b = 3;

	double c = 5.5;
	double d = 10.0;

	std::string s = "Jan";

	std::cout << std::endl << max(a, b, s) << std::endl;
	std::cout << std::endl << max(c, d, s) << std::endl;

	return 0;
}