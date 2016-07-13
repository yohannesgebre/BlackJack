#include <vector>
#include "card.h"
//deck of cards interface

//shuffle
//deal cards?


class Exception_empty_deck {};


class Deck
{
public:
	Deck(int number_of_cards = 52);
	Card draw_card();
	bool is_empty();
	//Precondition: Assumes a deck of less than 32000 cards
	void shuffle();

private:
	std::vector<Card> deck;
	int top;
	int cards_left;
};