#include <iostream>

int main()
{
	unsigned int array_size = 10;

	// Heap Allocation
	int *p = new int[array_size];

	for (int i = 0; i < array_size; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < array_size; i++)
	{
		std::cout << p[i] << std::endl;
	}

	// Heap De-Allocation
	delete[] p;

	return 0;
}