#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>

using std::string;
using std::vector;

double div(double a, double b)
{
	if (b == 0.0)
	{
		throw "Division by zero!";
	}

	return a / b;
}

int main()
{
	double x = 10.0;
	double y = 0.0;
	double z = 0.0;

	try
	{
		z = div(x, y);
		std::cout << z << std::endl;
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}

	return 0;
}