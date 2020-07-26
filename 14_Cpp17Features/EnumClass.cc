//#include <iostream>
//
//// 1.) + 2.)
//enum Colors
//{
//	RED		= 0,
//	GREEN	= 1,
//	BLUE	= 2,
//};
//
////unsigned int RED = 42;
//
//// 1.) + 2.)
//enum Colors2
//{
//	RED2	= 0,
//	GREEN2	= 1,
//	BLUE2	= 2,
//};
//
//// 3.)
//enum class Colors3 : unsigned char
//{
//	RED		= 0,
//	GREEN	= 1,
//	BLUE	= 2,
//};
//
//enum class Colors4 : unsigned char
//{
//	RED = 0,
//	GREEN = 1,
//	BLUE = 2,
//};
//
//
//// 1.) Two Enums cannot share the same names
//// 2.) No variable can have a name which is already in some enumeration
//// 3.) Enums are not type safe
//int main()
//{
//	// 1.) + 2.)
//	enum Colors c1 = Colors::RED;
//
//	enum Colors2 c2 = Colors2::RED2;
//
//	// 3.)
//	double val = 42.42;
//
//	if (val == c1)
//	{
//		std::cout << "Equal" << std::endl;
//	}
//	
//	enum class Colors3 c3 = Colors3::RED;
//	enum class Colors3 c4 = Colors3::RED;
//
//	unsigned char a = 'a';
//
//	if (a == c3)
//	{
//		std::cout << "Equal" << std::endl;
//	}
//
//	
//	return 0;
//}