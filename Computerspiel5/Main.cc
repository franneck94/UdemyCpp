#include <iostream>
#include <stdlib.h>

#include "Game3.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	bool repeat = true;
	Game game(10, 10);

	while (true)
	{
		game.start_game();

		cout << "Play again? (0=N, 1=Y)" << endl;
		cin >> repeat;

		if (repeat == 0)
			break;

		system("CLS");
	}

	return 0;
}