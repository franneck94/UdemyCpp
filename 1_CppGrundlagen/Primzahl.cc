//#include <iostream>
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//	// Lest eine positive ganze Zahl vom User ein.
//	// Ueberprueft, ob diese Zahl eine Primzahl ist.
//	// Primzahlen: Nur durch sich selbst und 1 (ohne Rest) teilbar.
//	bool is_prime = true;
//	unsigned int number;
//
//	cout << "Please enter a number: ";
//	cin >> number;
//
//	// 9
//	// [2, 3, 4, 5, 6, 7, 8]
//	for (int i = 3; i < number; i++)
//	{
//		if (number % i == 0)
//		{
//			is_prime = false;
//			break;
//		}
//	}
//
//	if (is_prime == false)
//		cout << "The number " << number << " is not a prime number!" << endl;
//	else
//		cout << "The number " << number << " is a prime number!" << endl;
//
//	return 0;
//}