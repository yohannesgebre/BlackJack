#ifndef HAND_H
#define HAND_H
#include <iostream>

class Hand
{
public:
	Hand();
	void display_hand();
private:
	//maybe have a vector of cards ???
	int total;
};

#endif