#include <iostream>

// Local copy (Call by Value)
void f(int *p_function)
{
	// The memory adress of the heap variable, where the pointer the points to
	std::cout << p_function << std::endl;
	std::cout << "Adress of p_function pointer location on the heap (inside):" << p_function << std::endl; // 00FAF180
																										   // The value of the heap variable, where the pointer the points to
	std::cout << *p_function << std::endl;
	// Memory adress of the pointer itself
	std::cout << "Adress of p_function:" << &p_function << std::endl; // 008FF998
}

void g(int number)
{
	// The value of the variable
	std::cout << number << std::endl;
	// The memory adress of the variable
	std::cout << "Adress of number (inside):" << &number << std::endl; // 008FF998
}

int main()
{
	int *p_number = new int{4};
	std::cout << "Adress of p_number pointer location on the heap (outside):" << p_number << std::endl; // 00FAF180
	std::cout << "Adress of p_number (outside):" << &p_number << std::endl;								// 008FF99C
	f(p_number);

	std::cout << std::endl;

	int normal_number = 7;
	std::cout << "Adress of normal_number (inside):" << &normal_number << std::endl; // 008FF9A0
	g(normal_number);

	delete p_number;

	return 0;
}