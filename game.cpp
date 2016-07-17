#include <iostream>
#include <ctime>
#include<cstdlib>
#include <string>

using namespace std;

//prototypes...
class  Card
{
public:
Card();
void game(void);
int hand(int, string);
void hit_or_stand(int &);
void winner(int, int);
int randomising(int, int);

};
Card::Card()
{
}
void Card::game()
{
        //play one hand of 21

        //randomize the cards
        srand((int) time(0));

       // deal the cards
         int person = deal(2, "Your Cards:");
         cout << " = " << person << endl;
         int house = deal(2, "Computers Cards:");
         cout << " = " << house << endl;

        // Ask if human wants a hit and keep hitting...
        hit_or_stand(person);
        cout << endl;

       //Determine if computer takes a hit
       while ((house < person) && (house <= 21) && (person <= 21))
	   {
               house += deal(1, "The Computer takes a card ");
               cout << endl;
        }

       //show who won....
       winner(person, house);
}

void Card::winner(int playerScore, int houseScore)
//Compare the scores to see who won
{
		if (playerScore == 21)
		{
			cout << "You have 21. You win!" << endl;
		}
		else if ((playerScore < 21) && (playerScore > houseScore))
		{
			cout << "You have the closer hand to 21. You win!" << endl;
		}
		else 
		{		
			cout << "The computer wins, sorry try again." << endl;
		}
}



int Card::deal(int numberOfCards, string message)
//This function deals the cards
{
	
	int return_value = 0;
	int value = 0;

	for (int a = 0; a <= numberOfCards; a++)
	{
		int cards = a; 
		while(cards--)
			{
				value = Random(0,10); 
				cout << value << " "; 
				if(cards) 
					cout << " , ";
				return_value += value;
				}
		}
	return return_value;
}


void Card::hit_or_stand(int &playerScore)//This function asks the human if they want another card -- 'a hit'
{
	int cardCount = 0;
	char wantCard = "y" || "n";
	int cardTotal = 0;
	cardTotal = playerScore;
	cout << "Would you like another card?"; 
	while (wantCard == 'Y' || wantCard == 'y')
	{
		if ((cardTotal > 0 ) && (cardTotal < 21))
		cardCount += 1;
		cardTotal += Random(0,10); 
		cout << "Your total is: " << cardTotal;
		cout << "Do you want another card?";
		cin >> wantCard;
		if (wantCard == 'Y' || wantCard == 'y')
		{
			cout << cardTotal + dealCards(1, "You take a card."); // adds humanScore to deal()
		}
		else 
		{
			cout << "You decide to stand";
		}
		if (cardTotal > 21) 
		{
			cout << "You have gone over 21, You Lose";
		}
	}
}
		


int Card::randomising(int lowerLimit, int upperLimit)
{
//returns a random number within the given boundary
	return 1 + rand() % (upperLimit - lowerLimit + 1);
}
