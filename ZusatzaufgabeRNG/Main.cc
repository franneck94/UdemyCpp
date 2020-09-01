#include <iostream>
#include <time.h>

#include "RNG.h"

int main()
{
	unsigned int seed = time(NULL);

	unsigned int random_number1;
	unsigned int random_number2;

	unsigned int lb = 0;
	unsigned int ub = 100;

	RNG<unsigned int> r1(seed);
	RNG<unsigned int> r2(seed);

	for (int i = 0; i < 33; ++i)
	{
		random_number1 = r1.randomNumberGenerator();
		std::cout << "i = " << i << " number = " << random_number1 << std::endl;

		random_number2 = r2.randomNumberGeneratorRange(lb, ub);
		std::cout << "i = " << i << " number = " << random_number2 << std::endl << std::endl;
	}

	return 0;
}