#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	double zahl1;
	double zahl2;
	double ergebnis;

	cout << "Bitte gebe eine Zahl ein: ";
	cin >> zahl1;
	cout << "Bitte gebe eine weitere Zahl ein: ";
	cin >> zahl2;

	// Rechenoperationen: Mult *, Add +, Subtr -, Div /
	ergebnis = zahl1 * zahl2;
	cout << "Ergebnis Multiplikation: " << ergebnis << endl;

	ergebnis = zahl1 + zahl2;
	cout << "Ergebnis Addition: " << ergebnis << endl;

	ergebnis = zahl1 - zahl2;
	cout << "Ergebnis Subtraktion: " << ergebnis << endl;

	ergebnis = zahl1 / zahl2;
	cout << "Ergebnis Division: " << ergebnis << endl;


	return 0;
}