#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	// 1: auto val : vec (COPY BY VALUE) VERÄNDERN DER LOKALEN KOPIEN
	// 2: auto &val : vec (CALL BY REFERENCE) VERÄNDERN IM EIGN. VECTOR
	// 3: const auto &val : vec (CALL BY REFERENCE) KEIN VERÄNDERN IM EIGN. VECTOR
	// 4: const auto val : vec (COPY BY VALUE) KEIN VERÄNDERN DER LOKALEN KOPIEN

	std::vector<int> vec(10, 0);
	std::iota(vec.begin(), vec.end(), 1);

	for (const auto &val : vec)
	{
		std::cout << val << " " << &val << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << vec[i] << " " << &vec[i] << std::endl;
	}

	return 0;
}