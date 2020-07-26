//#include <iostream>
//
//#include "Spiel.h"
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//// Definition
//void game()
//{
//	// b_gewonnen
//	bool b_gewonnen = false;
//	cout << "Willkommen bei meinem Gluecks-Spiel!" << endl;
//
//	while (b_gewonnen == false)
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
//				b_gewonnen = true;
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
//}