#include <iostream>
#include <algorithm>
#include <numeric>
#include <experimental/vector>

bool is_odd(int i)
{
	return (i % 2 == 1);
}

bool is_even(int i)
{
	return (i % 2 == 0);
}

bool third(int i)
{
	return (i % 3 == 0);
}

int main()
{
	std::vector<int> my_vector(10, 0);
	std::iota(my_vector.begin(), my_vector.end(), 0);

	for (int i = 0; i < my_vector.size(); ++i)
	{
		std::cout << "Vorher: " << my_vector[i] << std::endl;
	}
	std::cout << std::endl;

	// For GCC
	std::experimental::fundamentals_v2::erase(my_vector, is_even);

	for (int i = 0; i < my_vector.size(); ++i)
	{
		std::cout << "Nachher: " << my_vector[i] << std::endl;
	}

	return 0;
}