#ifndef GAME_H
#define GAME_H
#include <iostream>

class Game
{
public:
	Game();

private:
	bool game_is_over;
	Deck deck;
	Hand dealer;
	Hand player;

};

#endif