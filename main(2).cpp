#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "deck.h"
#include <windows.h>
using namespace std;

void gotoxy(short x, short y)

{
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	Deck deck;
	srand(time(0));
	deck.shuffle();

	
	
	return 0;
}
