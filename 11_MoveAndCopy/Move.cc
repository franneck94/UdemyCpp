#include <iostream>
#include <string>

#include "DynArrayMove.h"

using std::string;

int main()
{
	DynamicArray<double> a(1, 3);
	std::cout << "Adresse a: " << a.m_data << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << a[i];
	}
	std::cout << std::endl;

	// Move Constructor
	DynamicArray<double> b(std::move(a));
	std::cout << "Adresse b: " << b.m_data << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << b[i];
	}
	std::cout << std::endl;

	// MOve Assignment Operator
	DynamicArray<double> a2(1, 3);
	std::cout << "Adresse a2: " << a2.m_data << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << a2[i];
	}
	std::cout << std::endl;

	DynamicArray<double> c = std::move(a2);
	std::cout << "Adresse c: " << c.m_data << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << c[i];
	}
	std::cout << std::endl;

	return 0;
}