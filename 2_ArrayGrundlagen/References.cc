//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//// Local copy (Call by Value)
//void f(int* p_function)
//{
//	cout << "Function f: " << endl;
//	cout << "Adress of p_function pointer location on the heap (inside):" << p_function << endl; // 015BF040
//	cout << "Adress of p_function:" << &p_function << endl << endl; // 00F7F8BC
//}
//
//// Reference (&): Call-by-Reference
//void f2(int* &p_function)
//{
//	cout << "Function f2: " << endl;
//	cout << "Adress of p_function pointer location on the heap (inside):" << p_function << endl; // 015BF040
//	cout << "Adress of p_function:" << &p_function << endl << endl; // 00F7F8B8
//}
//
//// Local copy (Call by Value)
//void g(int number)
//{
//	cout << "Function g: " << endl;
//	cout << "Adress of number (inside):" << &number << endl; // 00F7F8BC
//}
//
//// Reference (&): Call-by-Reference
//void g2(int &number)
//{
//	cout << "Function g2: " << endl;
//	cout << "Adress of number (inside):" << &number << endl; // 00F7F8C0
//}
//
//int main()
//{
//	int* p_number = new int{ 4 };
//
//	cout << "Adress of p_number pointer location on the heap (outside):" << p_number << endl; // 015BF040
//	cout << "Adress of p_number (outside):" << &p_number << endl << endl; // 00F7F8B8
//
//	f(p_number);
//	f2(p_number);
//
//	int normal_number = 7;
//
//	cout << "Adress of normal_number (inside):" << &normal_number << endl; // 00F7F8C0
//
//	g(normal_number);
//	g2(normal_number);
//
//	delete p_number;
//
//	return 0;
//}