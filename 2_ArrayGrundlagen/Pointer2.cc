//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main()
//{
//	// Heap allocation
//	int* p_zahl = nullptr;
//	p_zahl = new int{ 4 };
//
//	// The memory adress of the heap variable, where the pointer the points to
//	cout << p_zahl << endl;
//	if (p_zahl != nullptr)
//	{
//		// The value of the heap variable, where the pointer the points to
//		cout << *p_zahl << endl;
//		// Memory adress of the pointer itself
//		cout << &p_zahl << endl;
//	}
//
//	// Heap de-allocation
//	delete p_zahl;
//	p_zahl = nullptr;
//
//	// The memory adress of the heap variable, where the pointer the points to
//	cout << p_zahl << endl;
//	if (p_zahl != nullptr)
//	{
//		// The value of the heap variable, where the pointer the points to
//		cout << *p_zahl << endl;
//		// Memory adress of the pointer itself
//		cout << &p_zahl << endl;
//	}
//
//	return 0;
//}