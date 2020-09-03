#include <iostream>

#define LEN_X 10
#define LEFT 'a'
#define RIGHT 'd'

int main()
{
	// LEN_X = 10
	// Wir haben 10 Spielfelder insgesamt
	// Pos 0: Start, Pos 9: Ziel
	unsigned int player_pos = 0;
	unsigned int start = 0;
	unsigned int goal = LEN_X - 1;

	char move;
	bool finished = false;

	while (!finished)
	{
		// Gebe den GameState aus (gebe das Spielbrett aus)
		for (int i = 0; i < LEN_X; i++)
		{
			if (i != player_pos && i != goal && i != start)
				std::cout << '.';
			else if (i == player_pos)
				std::cout << 'P';
			else if (i == goal || i == start)
				std::cout << '|';
		}

		std::cin >> move;

		// Fuehre den eingegebenen move aus
		if (move == LEFT)
		{
			player_pos--;
			std::cout << "You moved left!" << std::endl;
		}
		else if (move == RIGHT)
		{
			player_pos++;
			std::cout << "You moved right!" << std::endl;
		}
		else
		{
			std::cout << "Unrecognized move!" << std::endl;
		}

		// Ueberpreufe ob das Spiel gewonnen ist
		if (player_pos == goal)
		{
			std::cout << "You won the game!" << std::endl;
			finished = true;
		}
		else
		{
			finished = false;
		}
	}

	return 0;
}