#include <iostream>

// // 1. LValue (Copy by Value)
// void f(int z)
// {
// 	std::cout << "LValue (Copy by Value): " << z << " " << &z << std::endl << std::endl;
// }

// 2. LValue Reference
void f(int &z)
{
	std::cout << "LValue Reference: " << z << " " << &z << std::endl;
}

// // 3. Const LValue Reference
// void f(const int &z)
// {
// 	std::cout << "Const LValue Reference: " << z << " " << &z << std::endl;
// }

// // 4. RValue Reference
// void f(int &&z)
// {
// 	std::cout << "RValue Reference: " << z << " " << &z << std::endl << std::endl;
// }

int main()
{
	int a = 3;		  // LValue
	const int b = 3;  // const LValue
	int &c = a;		  // LValue reference
	const int &d = 3; // const LValue reference

	std::cout << "a main: " << a << " " << &a << std::endl;
	f(a); // LValue => LValue Reference

	std::cout << "b main: " << b << " " << &b << std::endl;
	f(b); // const LValue => Const LValue Reference:

	std::cout << "c main: " << c << " " << &c << std::endl;
	f(c); // LValue reference => LValue Reference

	f(3); // RValue => Const LValue Reference

	return 0;
}