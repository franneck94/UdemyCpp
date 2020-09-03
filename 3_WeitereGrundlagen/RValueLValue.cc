//#include <iostream>
//
//void f(const int &z)
//{
//	std::cout << z << std::endl;
//}
//
//// LValue (Left): Variable mit einer bestimmten Speicher-Adresse
//// RValue (Right): "Variable" ohne eine bestimmte Speicher-Adresse
//int main()
//{
//	int a = 3; // LValue
//	const int b = 3; // const LValue
//	int &c = a; // LValue reference
//
//	f(a); // LValue
//	f(b); // const LValue
//	f(c); // LValue reference
//	f(3); // RValue
//
//	return 0;
//}