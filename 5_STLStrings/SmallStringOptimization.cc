//#include <iostream>
//#include <string>
//#include <cstdlib>
//
//void* operator new(std::size_t n)
//{
//	std::cout << "I am allocating on the heap: " << n << std::endl;
//
//	return malloc(n);
//}
//
//void test_sso()
//{
//	std::size_t string_size = 1000;
//
//	for (int run = 0; run < 10000000; ++run)
//	{
//		std::string s(string_size, 'a');
//	}
//}
//
//int main()
//{
//	std::size_t string_size = 64;
//
//	for (std::size_t i = 0; i < string_size; ++i)
//	{
//		std::string s(i, 'a');
//		std::cout << i << ' ' << s << std::endl;
//	}
//
//	//test_sso();
//
//	return 0;
//}