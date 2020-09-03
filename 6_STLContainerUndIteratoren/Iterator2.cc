#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <list>

int main()
{
	std::vector<int> my_vector(5, 0);
	std::iota(my_vector.begin(), my_vector.end(), 5);
	std::list<int> my_list(my_vector.begin(), my_vector.end());

	auto it = my_list.begin();
	std::advance(it, 2);

	// 5, 6, 7, 8, 9
	std::cout << my_vector[2] << std::endl;						// 7
	std::cout << *it << std::endl;								// 7
	std::cout << std::distance(it, my_list.end()) << std::endl; // 3
	std::cout << *std::prev(it) << std::endl;					// 6
	std::cout << *std::next(it) << std::endl;					// 8

	return 0;
}