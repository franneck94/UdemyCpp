#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void print_double_vector(const std::vector<double> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << "Vec[" << i << "] = " << vec[i] << std::endl;
	}

	std::cout << std::endl;
}

bool sort_descending(const double &i, const double &j)
{
	return i > j;
}

bool sort_ascending(const double &i, const double &j)
{
	return i < j;
}

int main()
{
	std::vector<double> my_vector(10, 0);

	std::iota(my_vector.begin(), my_vector.end(), 3.0);
	print_double_vector(my_vector);

	std::sort(my_vector.begin(), my_vector.end() - 2, sort_descending);
	print_double_vector(my_vector);

	std::sort(my_vector.begin(), my_vector.end() - 2, sort_ascending);
	print_double_vector(my_vector);

	// Ascending is default
	std::sort(my_vector.begin(), my_vector.end());
	print_double_vector(my_vector);

	return 0;
}