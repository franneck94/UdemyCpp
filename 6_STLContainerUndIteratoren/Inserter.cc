#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <list>

int main()
{
	std::vector<int> my_vector(5, 0);
	std::iota(my_vector.begin(), my_vector.end(), 5);

	std::vector<int> my_vector2(5, 0);
	std::iota(my_vector2.begin(), my_vector2.end(), 10);

	std::vector<int> my_vector3;

	// Inserter (Ben�tigt Insert)
	std::copy(my_vector.begin(), my_vector.end(),
			  std::inserter(my_vector3, my_vector3.end()));
	std::copy(my_vector2.begin(), my_vector2.end(),
			  std::inserter(my_vector3, my_vector3.end()));

	std::cout << "Starting Inserter!" << std::endl;
	for (const auto &val : my_vector3)
	{
		std::cout << val << std::endl;
	}

	std::vector<int> my_vector4;

	// BackInserter (Ben�tigt push_back)
	std::copy(my_vector.begin(), my_vector.end(),
			  std::back_inserter(my_vector4));
	std::copy(my_vector2.begin(), my_vector2.end(),
			  std::back_inserter(my_vector4));

	std::cout << "Starting BackInserter!" << std::endl;
	for (const auto &val : my_vector4)
	{
		std::cout << val << std::endl;
	}

	return 0;
}