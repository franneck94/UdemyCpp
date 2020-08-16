//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//// Local copy (Call by Value)
//void f(int* p_function)
//{
//	// The memory adress of the heap variable, where the pointer the points to
//	cout << p_function << endl;
//	cout << "Adress of p_function pointer location on the heap (inside):" << p_function << endl; // 00FAF180
//	// The value of the heap variable, where the pointer the points to
//	cout << *p_function << endl;
//	// Memory adress of the pointer itself
//	cout << "Adress of p_function:" << &p_function << endl; // 008FF998
//}
//
//void g(int number)
//{
//	// The value of the variable
//	cout << number << endl;
//	// The memory adress of the variable
//	cout << "Adress of number (inside):" << &number << endl; // 008FF998
//}
//
//int main()
//{
//	int* p_number = new int{ 4 };
//	cout << "Adress of p_number pointer location on the heap (outside):" << p_number << endl; // 00FAF180
//	cout << "Adress of p_number (outside):" << &p_number << endl; // 008FF99C
//	f(p_number);
//
//	cout << endl;
//
//	int normal_number = 7;
//	cout << "Adress of normal_number (inside):" << &normal_number << endl; // 008FF9A0
//	g(normal_number);
//	
//	delete p_number;
//
//	return 0;
//}