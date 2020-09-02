#include <iostream>
#include <stdlib.h>

#include "Game2.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	bool repeat = true;

	while (true)
	{
		game();

		cout << "Play again? (0=N, 1=Y)" << endl;
		cin >> repeat;

		if (repeat == 0)
			break;

		system("CLS");
	}

	return 0;
}