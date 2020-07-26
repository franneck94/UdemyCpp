#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

int check_even(int val)
{
	if (val % 2 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	std::vector<int> my_vector(10, 0);
	std::iota(my_vector.begin(), my_vector.end(), 0);

	for (const auto &val : my_vector)
	{
		std::cout << val << std::endl;
	}
	std::cout << std::endl;

	std::vector<int> my_result(10, 0);
	std::vector<int> my_result2;

	// TRANSFORM:  Speichert True oder False in my_result
	// bei Gerade/Ungerade Zahl in my_vector haben
	// WICHTIG: Speichert wirklich den return Wert ab!
	std::transform(my_vector.begin(), my_vector.end(), my_result.begin(),
		[](int val) -> int {if (val % 2 == 0) return true; else return false; });

	for (const auto &val : my_result)
	{
		std::cout << val << std::endl;
	}
	std::cout << std::endl;

	// COPY IF: Speichert den Wert in my_result2
	// bei Geraden/Ungeraden Zahl aus my_vector
	// WICHTIG: Speichert den Value bei return True
	std::copy_if(my_vector.begin(), my_vector.end(), std::back_inserter(my_result2),
		[](int val) -> int {if (val % 2 == 0) return true; else return false; });

	for (const auto &val : my_result2)
	{
		std::cout << val << std::endl;
	}
	std::cout << std::endl;

	return 0;
}