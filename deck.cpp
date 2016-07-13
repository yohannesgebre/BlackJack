#include "deck.h"
using namespace std;

Deck::Deck(int number_of_cards)
{
	Card card;

	top = 0;
	cards_left = number_of_cards;

	for (int i = 0; i < cards_left; i++)
	{
		deck.push_back(card);
		card++;
	}
}

Card Deck::draw_card()
{
	int temp = top;
	if (cards_left == 0)
	{
		throw Exception_empty_deck();
	}
	if (cards_left > 0)
	{
		cards_left--;
	}
	if (cards_left > 0)
	{
		top++;
	}
	return deck[temp];
}

bool Deck::is_empty()
{
	return cards_left == 0;
}

void Deck::shuffle()
{
	unsigned int index1;
	unsigned int index2;

	for (int i = 0; i < 10000; i++)
	{
		index1 = rand() % deck.size();
		index2 = rand() % deck.size();
		swap(deck[index1], deck[index2]);
	}
}