#include <iostream>
#include <string>

#include "DynArray Move.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	DynamicArray<double> a(1, 3);
	cout << "Adresse a: " << a.m_data << endl;
	for (int i = 0; i != 3; ++i)
	{
		cout << a[i];
	}
	cout << endl;

	// Move Constructor
	DynamicArray<double> b(std::move(a));
	cout << "Adresse b: " << b.m_data << endl;
	for (int i = 0; i != 3; ++i)
	{
		cout << b[i];
	}
	cout << endl;

	// MOve Assignment Operator
	DynamicArray<double> a2(1, 3);
	cout << "Adresse a2: " << a2.m_data << endl;
	for (int i = 0; i != 3; ++i)
	{
		cout << a2[i];
	}
	cout << endl;

	DynamicArray<double> c = std::move(a2);
	cout << "Adresse c: " << c.m_data << endl;
	for (int i = 0; i != 3; ++i)
	{
		cout << c[i];
	}
	cout << endl;

	return 0;
}