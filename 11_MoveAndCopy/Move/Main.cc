#include <iostream>

#include "DynamicArray.h"

int main()
{
	// Constructor
	DynamicArray<double> a(1, 3);
	for (int i = 0; i != 3; ++i)
	{
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;

	// Move Constructor
	DynamicArray<double> b(std::move(a));
	std::cout << "Move constructor: " << b.m_data << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << b[i] << ", ";
	}
	std::cout << std::endl;

	// Move Assignment Operator
	DynamicArray<double> c(2.0, 3);
	std::cout << "Before move assignment: " << c.m_data << std::endl;
	c = std::move(b);
	std::cout << "After move assignment: " << c.m_data << std::endl;
	for (int i = 0; i != 3; ++i)
	{
		std::cout << c[i] << ", ";
	}
	std::cout << std::endl;

	return 0;
}