//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main()
//{
//	// All years which are perfectly divisible by 4 are leap years except for century years 
//	// (years ending with 00) which is leap year only it is perfectly divisible by 400.
//
//	unsigned int year;
//	cout << "Please enter the year: ";
//	cin >> year;
//	cout << "You entered the year: " << year << endl;
//
//	if (year % 4 == 0)
//	{
//		if (year % 100 == 0)
//		{
//			if (year % 400 == 0)
//			{
//				cout << "The year: " << year << " is a leap year!" << endl;
//			}
//			else
//			{
//				cout << "The year: " << year << " is not a leap year!" << endl;
//			}
//		}
//		else
//		{
//			cout << "The year: " << year << " is a leap year!" << endl;
//		}
//	}
//	else
//	{
//		cout << "The year: " << year << " is not a leap year!" << endl;
//	}
//
//	return 0;
//}