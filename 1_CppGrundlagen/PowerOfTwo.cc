//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//
//bool is_power_of_two(unsigned int number)
//{
//	bool is_power = false;
//
//	while (number > 1)
//	{	
//		if (number % 2 == 1)
//		{
//			is_power = false;
//
//			break;
//		}
//		else
//		{
//			number = number / 2;
//
//			is_power = true;
//		}
//	}
//
//	return is_power;
//}
//
//int main()
//{
//	/*
//	Given an integer, determine if the number is a power of two.
//
//	Input : 32 (2^5)
//	Output : true
//	
//	Input: 218
//	Output: false
//	*/
//	unsigned int number1 = 218;
//	std::cout << number1 << " " << is_power_of_two(number1) << std::endl;
//
//	unsigned int number2 = 257;
//	std::cout << number2 << " " << is_power_of_two(number2) << std::endl;
//
//	unsigned int number3 = 64;
//	std::cout << number3 << " " << is_power_of_two(number3) << std::endl;
//
//	unsigned int number4 = 256;
//	std::cout << number4 << " " << is_power_of_two(number4) << std::endl;
//
//	return 0;
//}