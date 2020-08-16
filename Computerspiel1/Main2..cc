//#include <iostream>
//
//#define LEN_X 10
//#define LEFT 'a'
//#define RIGHT 'd'
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main()
//{
//	// LEN_X = 10
//	// Wir haben 10 Spielfelder insgesamt
//	// Pos 0: Start, Pos 9: Ziel
//	unsigned int player_pos = 0;
//	unsigned int start = 0;
//	unsigned int goal = LEN_X - 1;
//
//	char move;
//	bool finished = false;
//
//	while (!finished)
//	{
//		// Gebe den GameState aus (gebe das Spielbrett aus)
//		for (int i = 0; i < LEN_X; i++)
//		{
//			if (i != player_pos && i != goal && i != start)
//				cout << '.';
//			else if (i == player_pos)
//				cout << 'P';
//			else if (i == goal || i == start)
//				cout << '|';
//		}
//
//		cin >> move;
//
//		// Fuehre den eingegebenen move aus
//		if (move == LEFT)
//		{
//			player_pos--;
//			cout << "You moved left!" << endl;
//		}
//		else if (move == RIGHT)
//		{
//			player_pos++;
//			cout << "You moved right!" << endl;
//		}
//		else
//		{
//			cout << "Unrecognized move!" << endl;
//		}
//
//		// Ueberpreufe ob das Spiel gewonnen ist
//		if (player_pos == goal)
//		{
//			cout << "You won the game!" << endl;
//			finished = true;
//		}
//		else
//		{
//			finished = false;
//		}
//	}
//
//	return 0;
//}