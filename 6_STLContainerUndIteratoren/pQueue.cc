#include <iostream>
#include <queue>
#include <vector>
#include <functional>

typedef std::priority_queue<int, std::vector<int>, std::less<int>> priority_queue_less;
typedef std::priority_queue<int, std::vector<int>, std::greater<int>> priority_queue_greater;

void execute(priority_queue_less &pq)
{
	while (!pq.empty())
	{
		std::cout << pq.top() << std::endl;
		pq.pop();
	}

	std::cout << std::endl;
}

void execute(priority_queue_greater &pq)
{
	while (!pq.empty())
	{
		std::cout << pq.top() << std::endl;
		pq.pop();
	}

	std::cout << std::endl;
}

int main()
{
	std::priority_queue<int, std::vector<int>, std::less<int>> my_pq1;
	my_pq1.push(10);
	my_pq1.push(23);
	my_pq1.push(42);

	std::vector<int> data = { 10, 23, 42 };
	std::priority_queue<int, std::vector<int>, std::greater<int>> my_pq2(data.begin(), data.end());

	execute(my_pq1);
	execute(my_pq2);

	return 0;
}