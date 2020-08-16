#include <iostream>
#include <string>
#include "DynArray.h"
#include "AlgoArray.h"
 
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	DynamicArray a = create_dynamic_array(1, 10);
	double mean_a = mean(a);
	double sum_a = sum(a);

	for (int i = 0; i != a.m_length; i++)
		cout << endl << a.m_data[i];
	cout << endl << "Mean: " << mean_a;
	cout << endl << "Sum: " << sum_a << endl;

	push_back(a, 1337);
	for (int i = 0; i != a.m_length; i++)
		cout << endl << a.m_data[i];
	cout << endl;

	pop_back(a);
	for (int i = 0; i != a.m_length; i++)
		cout << endl << a.m_data[i];
	cout << endl;


	DynamicArray b = create_dynamic_array(1, 4);
	b.m_data[0] = 1;
	b.m_data[1] = 2;
	b.m_data[2] = 3;
	b.m_data[3] = 4;

	cout << "Var(b) = " << variance(b) << " std(b) = " << stddev(b) << endl;

	return 0;
}