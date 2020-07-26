//#include <iostream>
//
////// 1. LValue (Copy by Value)
////void f(int z)
////{
////	std::cout << "LValue (Copy by Value): " << z << " " << &z << std::endl << std::endl;
////}
//
//// 2. LValue Reference
//// LValue okay
//void f(int &z)
//{
//	std::cout << "LValue Reference: " << z << " " << &z << std::endl << std::endl;
//}
//
//// 3. Const LValue Reference
//// LValue und RValue okay
//void f(const int &z)
//{
//	std::cout << "Const LValue Reference: " << z << " " << &z << std::endl << std::endl;
//}
//
////// 4. RValue Reference
////void f(int &&z)
////{
////	std::cout << "RValue Reference: " << z << " " << &z << std::endl << std::endl;
////}
//
//// LValue (Left): Variable mit einer bestimmten Speicher-Adresse
//// RValue (Right): Variable ohne eine bestimmte Speicher-Adresse 
//int main()
//{
//	int a = 3; // LValue
//	const int b = 3; // const LValue
//	int &c = a; // LValue reference
//
//	std::cout << a << " " << &a << std::endl;
//	f(a); // LValue => LValue Reference
//
//	std::cout << b << " " << &b << std::endl;
//	f(b); // const LValue => Const LValue Reference:
//
//	std::cout << c << " " << &c << std::endl;
//	f(c); // LValue reference => LValue Reference
//
//	f(3); // RValue => Const LValue Reference
//
//	return 0;
//}