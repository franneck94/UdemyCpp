#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <functional>

void random_vector(std::vector<int> &vec)
{
	std::random_device seed_generator;
	std::mt19937 random_generator(seed_generator());
	std::uniform_int_distribution<int> random_distribution(-10, 10);

	for (auto &val : vec)
	{
		val = random_distribution(random_generator);
	}
}

int main()
{
	std::vector<int> vector_a(3, 0);
	std::vector<int> vector_b(3, 0);
	std::vector<int> vector_c(3, 0);

	random_vector(vector_a);
	random_vector(vector_b);

	// REDUCE
	int sum_vector_a = std::reduce(vector_a.begin(), vector_a.end());
	std::cout << "sum_vector_a = " << sum_vector_a << std::endl;

	int sum_vector_a_plus2 = std::reduce(vector_a.begin(), vector_a.end(), 2);
	std::cout << "sum_vector_a + 2 = " << sum_vector_a_plus2 << std::endl;

	// ACCUMULATE
	int sum_vector_b = std::accumulate(vector_b.begin(), vector_b.end(), 0);
	std::cout << "sum_vector_b = " << sum_vector_b << std::endl;

	int sum_vector_b_plus2 = std::accumulate(vector_b.begin(), vector_b.end(), 2);
	std::cout << "sum_vector_b + 2 = " << sum_vector_b_plus2 << std::endl;

	// ACCUMULATE with Multiplies<int>
	int product_vector_b = std::accumulate(vector_b.begin(), vector_b.end(), 1, std::multiplies<int>());
	std::cout << "product_vector_b = " << product_vector_b << std::endl;

	return 0;
}