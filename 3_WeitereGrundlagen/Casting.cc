//#include <iostream>
//
//// 1a. static_cast: convert object from one type to another (C++)
//// 1b. c-style casting (C)
//
//// C++ Casting vs. C Casting:
//// Easier to read, less prone to errors
//
//int main()
//{
//	double zahl = 3.14;
//	std::cout << zahl << std::endl;
//
//	int zahl2 = zahl;
//	std::cout << zahl2 << std::endl;
//
//	// C-Casting
//	float zahl3 = (float)(zahl); // (NEW_DTYPE)(VARIABLE_NAME)
//	std::cout << zahl3 << std::endl;
//
//	// C++ casting (static_cast) 
//	short zahl4 = static_cast<short>(zahl); // static_cast<NEW_DTYPE>(VARIABLE_NAME)
//	std::cout << zahl4 << std::endl;
//
//	// Example why C-Style casting is BAD!
//	char c = 42; // char needs 1-Byte: 0x0a
//	std::cout << c << std::endl;
//	//int* p = (int*)(&c); // int needs 4-Byte
//	//std::cout << *p << std::endl;
//
//	//int* p2 = static_cast<int*>(&c);
//
//
//	return 0;
//}