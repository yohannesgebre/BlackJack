#include <iostream>
#include "card.h"
#include <Windows.h>
using namespace std;

ostream& operator<<(ostream& out, Rank right)
{
	switch (right)
	{
	case Rank::ACE :
		out << 'A'; break;
	case Rank::TEN :
		out << 'T'; break;
	case Rank::JACK :
		out << 'J'; break;
	case Rank::QUEEN :
		out << 'Q'; break;
	case Rank::KING :
		out << 'K'; break;
	default:
		out << static_cast<int>(right);
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, Suit right)
{
	return out << static_cast<char>(right);
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	return out << card.rank << card.suit;
}

void Card::display_card()
{
	if (is_red())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_RED | FOREGROUND_INTENSITY |
			BACKGROUND_BLUE | BACKGROUND_GREEN |
			BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			BACKGROUND_BLUE | BACKGROUND_GREEN |
			BACKGROUND_RED | BACKGROUND_INTENSITY);
	}
	cout << *this;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
}

bool Card::is_red() const
{
	return suit == Suit::HEARTS || suit == Suit::DIAMONDS;
}
bool Card::is_black() const
{
	return suit == Suit::CLUBS || suit == Suit::SPADES;
}

Card& Card::operator++()
{
	cout << "pre increment" << endl;
	rank++;
	if (rank == Rank::ACE)
	{
		suit++;
	}
	return *this;
}

Card Card::operator++(int)
{
	Card stuff{ *this };
	rank++;
	if (rank == Rank::ACE)
	{
		suit++;
	}
	return stuff;
}

Rank& operator++(Rank& rank)
{
	switch (rank)
	{
	case Rank::ACE:
		rank = Rank::TWO;
		break;
	case Rank::TWO:
		rank = Rank::THREE;
		break;
	case Rank::THREE:
		rank = Rank::FOUR;
		break;
	case Rank::FOUR:
		rank = Rank::FIVE;
		break;
	case Rank::FIVE:
		rank = Rank::SIX;
		break;
	case Rank::SIX:
		rank = Rank::SEVEN;
		break;
	case Rank::SEVEN:
		rank = Rank::EIGHT;
		break;
	case Rank::EIGHT:
		rank = Rank::NINE;
		break;
	case Rank::NINE:
		rank = Rank::TEN;
		break;
	case Rank::TEN:
		rank = Rank::JACK;
		break;
	case Rank::JACK:
		rank = Rank::QUEEN;
		break;
	case Rank::QUEEN:
		rank = Rank::KING;
		break;
	case Rank::KING:
		rank = Rank::ACE;
		break;
	}
	return rank;
}

Rank operator++(Rank& rank, int)
{
	Rank old_rank = rank;
	switch (rank)
	{
	case Rank::ACE:
		rank = Rank::TWO;
		break;
	case Rank::TWO:
		rank = Rank::THREE;
		break;
	case Rank::THREE:
		rank = Rank::FOUR;
		break;
	case Rank::FOUR:
		rank = Rank::FIVE;
		break;
	case Rank::FIVE:
		rank = Rank::SIX;
		break;
	case Rank::SIX:
		rank = Rank::SEVEN;
		break;
	case Rank::SEVEN:
		rank = Rank::EIGHT;
		break;
	case Rank::EIGHT:
		rank = Rank::NINE;
		break;
	case Rank::NINE:
		rank = Rank::TEN;
		break;
	case Rank::TEN:
		rank = Rank::JACK;
		break;
	case Rank::JACK:
		rank = Rank::QUEEN;
		break;
	case Rank::QUEEN:
		rank = Rank::KING;
		break;
	case Rank::KING:
		rank = Rank::ACE;
		break;
	}
	return old_rank;
}

Suit& operator++(Suit& suit)
{
	switch (suit)
	{
	case Suit::HEARTS:
		suit = Suit::DIAMONDS;
		break;
	case Suit::DIAMONDS:
		suit = Suit::CLUBS;
		break;
	case Suit::CLUBS:
		suit = Suit::SPADES;
		break;
	case Suit::SPADES:
		suit = Suit::HEARTS;
		break;
	}
	return suit;
}

Suit operator++(Suit& suit, int)
{
	Suit old_suit = suit;

	switch (suit)
	{
	case Suit::HEARTS:
		suit = Suit::DIAMONDS;
		break;
	case Suit::DIAMONDS:
		suit = Suit::CLUBS;
		break;
	case Suit::CLUBS:
		suit = Suit::SPADES;
		break;
	case Suit::SPADES:
		suit = Suit::HEARTS;
		break;
	}
	return old_suit;
}
