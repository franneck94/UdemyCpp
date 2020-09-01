//#include <iostream>
//#include <vector>
//#include <limits>
//
//bool almost_equal(double x, double y, int ulp)
//{
//	return std::abs(x - y) <= std::numeric_limits<double>::epsilon();
//}
//
//int main()
//{
//	std::cout << "MINS: " << std::endl;
//	std::cout << "short: " << std::dec << std::numeric_limits<short>::min() << std::endl;
//	std::cout << "int: " << std::dec << std::numeric_limits<int>::min() << std::endl;
//	std::cout << "float: " << std::numeric_limits<float>::min() << std::endl;
//	std::cout << "double: " << std::defaultfloat << std::numeric_limits<double>::min() << std::endl;
//
//	std::cout << "MAXS: " << std::endl;
//	std::cout << "short: " << std::dec << std::numeric_limits<short>::max() << std::endl;
//	std::cout << "int: " << std::dec << std::numeric_limits<int>::max() << std::endl;
//	std::cout << "float: " << std::numeric_limits<float>::max() << std::endl;
//	std::cout << "double: " << std::defaultfloat << std::numeric_limits<double>::max() << std::endl;
//
//	double d1 = 0.2;
//	double d2 = 1 / (std::sqrt(5) * std::sqrt(5)); // == 1 / 5
//
//	std::cout.precision(17);
//	std::cout << d1 << std::endl;
//	std::cout << d2 << std::endl;
//
//	if (d1 == d2)
//	{
//		std::cout << "d1 == d2" << std::endl;
//	}
//	else
//	{
//		std::cout  << "d1 != d2" << std::endl;
//	}
//
//	if (almost_equal(d1, d2, 2))
//	{
//		std::cout << "d1 almost equals d2" << std::endl;
//	}
//	else
//	{
//		std::cout << "d1 does not almost equal d2" << std::endl;
//	}
//
//	return 0;
//}