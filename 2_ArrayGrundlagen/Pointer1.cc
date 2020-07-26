#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int number = 1337;
	cout << "Value of number: " << number << endl;
	cout << "Memory adress of number: " << &number << endl;

	// Pointer muss auf eine Speicheradresse zeigen
	// p: Memory Adress
	// *p: Value of that memory adress
	int* p = &number;
	cout << "The memory adress that the variable 'p' points to: " << p << endl;
	cout << "The value that the variable 'p' points to: " << *p << endl;

	return 0;
}