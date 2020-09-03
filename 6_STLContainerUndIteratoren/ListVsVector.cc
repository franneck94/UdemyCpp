#include <iostream>
#include <vector>
#include <list>
#include <numeric>

void vec_time()
{
	std::vector<int> data(100, 0);
	std::iota(data.begin(), data.end(), 0);

	std::vector<int> my_data(data.begin(), data.end());
	auto it = my_data.begin();

	for (int i = 0; i < 2'000; ++i)
	{
		it = my_data.insert(it, 0);
	}
}

void list_time()
{
	std::vector<int> data(100, 0);
	std::iota(data.begin(), data.end(), 0);

	std::list<int> my_data(data.begin(), data.end());

	for (int i = 0; i < 2'000; ++i)
	{
		my_data.push_front(0);
	}
}

int main()
{
	std::cout << "START" << std::endl;
	vec_time(); // 1951ms, 1757ms, 1979ms => 1895ms
	//list_time(); // 15ms, 18ms, 16ms => 16ms
	std::cout << "DONE" << std::endl;

	return 0;
}