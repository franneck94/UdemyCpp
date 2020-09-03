#include <iostream>

int modulo(int n1, int n2)
{
	// 10 / 3 = 3
	int step1 = n1 / n2;
	// rest = 10 - 3*3 = 1
	int step2 = n1 - (n2 * step1);

	return step2;
}

int main()
{
	int a = 1337;
	int b = 17;
	int m;

	m = modulo(a, b);

	std::cout << m << std::endl;

	return 0;
}