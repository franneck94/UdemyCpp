//#include <iostream>
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//	int anzahl_spiele;
//
//	cout << "Willkommen bei meinem Gluecks-Spiel!" << endl;
//	cout << "Wie viele Spiel-Durchlaeufe willst du spielen: ";
//	cin >> anzahl_spiele;
//
//	for (int i = 0; i < anzahl_spiele; i++)
//	{
//		int zahl;
//		cout << "Du bist im Spieldurchlauf Nummer: " << i << endl;
//		cout << "Bitte gebe eine Zahl aus dem Intervall [1, 10] ein: ";
//		cin >> zahl;
//
//		if (zahl >= 1 && zahl <= 10)
//		{
//			if (zahl == 4)
//			{
//				cout << "Du hast den Haupt-Preis gewonnen!" << endl;
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