#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

bool is_even(int i)
{
	return (i % 2 == 0);
}

int main()
{
	std::vector<int> my_vector(10, 0);
	std::iota(my_vector.begin(), my_vector.end(), 0);

	for (std::size_t i = 0; i < my_vector.size(); ++i)
	{
		std::cout << "Before: " << my_vector[i] << std::endl;
	}
	std::cout << std::endl;

	std::erase(my_vector, is_even);

	for (std::size_t i = 0; i < my_vector.size(); ++i)
	{
		std::cout << "After: " << my_vector[i] << std::endl;
	}

	return 0;
}