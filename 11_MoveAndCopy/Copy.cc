#include <iostream>
#include <string>

#include "DynArrayCopy.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	DynamicArray<double> a(1, 3);
	cout << "Adresse a: " << &a << endl;
	for (int i = 0; i != 3; ++i)
	{
		cout << a[i];
	}
	cout << endl;

	// Copy Constructor
	DynamicArray<double> b(a);
	cout << "Adresse b: " << &b << endl;
	for (int i = 0; i != 3; ++i)
	{
		cout << b[i];
	}
	cout << endl;

	// Copy Assignment Operator
	DynamicArray<double> c = a;
	cout << "Adresse c: " << &c << endl;
	for (int i = 0; i != 3; ++i)
	{
		cout << c[i];
	}
	cout << endl;

	return 0;
}