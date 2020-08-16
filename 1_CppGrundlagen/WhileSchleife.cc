//#include <iostream>
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//	bool gewonnen = false;
//	cout << "Willkommen bei meinem Gluecks-Spiel!" << endl;
//
//	while(gewonnen == false)
//	{
//		int zahl;
//		cout << "Bitte gebe eine Zahl aus dem Intervall [1, 10] ein: ";
//		cin >> zahl;
//
//		if (zahl >= 1 && zahl <= 10)
//		{
//			if (zahl == 4)
//			{
//				cout << "Du hast den Haupt-Preis gewonnen!" << endl;
//				gewonnen = true;
//			}
//			else if (zahl % 2 == 0)
//			{
//				cout << "Du hast einen Trost-Preis gewonnen!" << endl;
//			}
//			else
//			{
//				cout << "Du hast verloren!" << endl;
//			}
//		}
//		else
//		{
//			cout << "Du hast leider eine Zahl eingegeben, die nicht aus dem Intervall [1, 10] stammt!" << endl;
//		}
//	}
//
//	return 0;
//}