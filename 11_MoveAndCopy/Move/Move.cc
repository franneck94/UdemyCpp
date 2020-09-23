#include <iostream>

#include "DynArrayMove.h"

int main()
{
	DynamicArray<double> a(1, 3);
	std::cout << "Adresse a.m_length: " << &a.m_length << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << a[i];
	}
	std::cout << std::endl;

	// Move Constructor
	DynamicArray<double> b(std::move(a));
	std::cout << "Adresse b.m_length: " << &b.m_length << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << b[i];
	}
	std::cout << std::endl;

	// Move Assignment Operator
	DynamicArray<double> c;
	c = std::move(b);
	std::cout << "Adresse c.m_length: " << &c.m_length << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << c[i];
	}
	std::cout << std::endl;

	return 0;
}