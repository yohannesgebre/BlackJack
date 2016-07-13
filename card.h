#ifndef CARD_H
#define CARD_H
#include <iostream>

enum class Rank {
	ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
	NINE, TEN, JACK, QUEEN, KING
};

enum class Suit {
	HEARTS = 3, DIAMONDS, CLUBS, SPADES
};



std::ostream& operator<<(std::ostream& out, Rank right);
std::ostream& operator<<(std::ostream& out, Suit right);

Rank& operator++(Rank& rank);
Rank operator++(Rank& rank, int);
Suit& operator++(Suit& suit);
Suit operator++(Suit& suit, int);

class Card
{
public:
	Card() : rank{ Rank::ACE }, suit{ Suit::SPADES } {}
	Card(Rank rank, Suit suit) : rank{ rank }, suit{ suit } {}
	bool is_red() const;
	bool is_black() const;
	Rank get_rank() const {return rank;}
	Suit get_suit() const {return suit;}

	//choose not to make mutator functions

	friend std::ostream& operator<<(std::ostream& out, const Card& card);

	Card& operator++();
	Card operator++(int);

	void display_card();
private:
	Rank rank;
	Suit suit;

};

#endif