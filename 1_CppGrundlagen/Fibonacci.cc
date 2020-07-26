//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main()
//{
//	// In mathematics, the Fibonacci numbers, commonly denoted Fn, form a sequence, 
//	// called the Fibonacci sequence, such that each number is the sum of the two preceding ones, 
//	// starting from 0 and 1. That is:
//	// F_0 = 0, F_1 = 1
//	// F_n = F_(n-1) + F_(n-2)
//
//	cout << "Please enter n: ";
//	int n;
//	cin >> n;
//	cout << "You entered: " << n << endl;
//
//	int f_n_minus_2 = 0; // Start: F_0
//	cout << f_n_minus_2 << endl;
//	int f_n_minus_1 = 1; // Start: F_1
//	cout << f_n_minus_1 << endl;
//
//	int f_n;
//
//	// F_2 = F_1 + F_0
//	// F_3 = F_2 + F_1
//	for (int i = 2; i <= n; i++)
//	{
//		f_n = f_n_minus_1 + f_n_minus_2;
//		cout << f_n << endl;
//
//		f_n_minus_2 = f_n_minus_1;
//		f_n_minus_1 = f_n;
//	}
//
//
//	return 0;
//}