// Blackjack.cpp

#include"Blackjack.h"
#include"Card.h"
#include"Hand.h"
#include"Tools.h"
#include<iostream>
#include<string>
using namespace card_space;
using namespace hand_space;
using namespace std;
using namespace tools;

using namespace card_space;

namespace black_jack
{
	const int INITIAL_PURSE = 100;
	const bool FACE_UP = true;
	const bool FACE_DOWN = !FACE_UP;
	const int MAX_DEALER_HIT = 16;

	void blackjack(void)
	{
		playGames();
	}

	void playGames(void)
	{
		do		playGame();
		while	( getBool("Do you want to play again? ") );
	}

	void playGame(void)
	{
		int purse;
		setUpPurse(purse);
		processHands(purse);
	}

	void setUpPurse(int &purse)
	{
		purse = INITIAL_PURSE;
	}

	void processHands(int &purse)
	{
		do		playHand(purse);
		while	( purse > 0 && getBool("Another hand? ") );
	}

	void playHand(int &purse)
	{
		cout << endl;

		int playerBet;
		bet(purse, playerBet);

		Hand dealerHand, playerHand;
		dealHand(dealerHand, playerHand);
		settleBet(dealerHand, playerHand, playerBet, purse);
	}

	void bet(int purse, int&bet)
	{
		cout << "You have $" << purse << "." << endl;
		bet = getBoundedInt("Enter your bet: ", 1, purse);
	}

	void dealHand(Hand &dealerHand, Hand &playerHand)
	{
		dealInitialCards( dealerHand, playerHand );
		dealPlayerHits(playerHand);
		if ( !playerHand.isBusted()
				&& !playerHand.isBlackjack()
				&& !playerHand.isFiveUnder() )
			dealDealerHits(dealerHand);
	}

	void dealInitialCards(Hand &dealerHand, Hand &playerHand)
	{
		dealCard( playerHand, "Player", FACE_UP );
		dealCard( dealerHand, "Dealer", FACE_DOWN );
		dealCard( playerHand, "Player", FACE_UP );
		dealCard( dealerHand, "Dealer", FACE_UP );

		if ( playerHand.isBlackjack() ) cout << "Blackjack!" << endl;
	}

	void dealCard(Hand &hand, string who, bool faceUp)
	{
		Card card;
		hand.addCard(card);

		cout << who << " gets a "
			<< (faceUp ? card.name() : "card")
			<< "."
			<< endl;

		// one-liner:
		//hand.addCard( Card() );
	}

	void dealPlayerHits(Hand &playerHand)
	{
		while (true)
		{
			cout << "Player's total is " << playerHand.value() << "." << endl;
			if ( !getBool( "Would you like a hit? " ) ) break;

			dealCard( playerHand, "Player", FACE_UP );
			if ( playerHand.isBusted() )
			{
				cout << "Busted!." << endl;
				break;
			}
		}
	}

	void dealDealerHits(Hand &dealerHand)
	{
		cout << "Dealer's total is " << dealerHand.value() << "." << endl;
		while ( dealerHand.value() <= MAX_DEALER_HIT )
		{
			cout << "Dealer will take a hit." << endl;
			dealCard( dealerHand, "Dealer", FACE_UP );
			cout << "Dealer's total is " << dealerHand.value() << "." << endl;
		}
		if ( dealerHand.isBusted() )
			cout << "Dealer is busted!!" << endl;
	}

	bool dealerWins(Hand dealerHand, Hand playerHand)
	{
		return playerHand.isBusted()
				|| (!playerHand.isBlackjack()
					&& !playerHand.isFiveUnder()
					&& !dealerHand.isBusted()
					&& dealerHand.value() >= playerHand.value());
	}

	void settleBet(Hand dealerHand, Hand playerHand, int bet, int &purse)
	{
		if ( dealerWins(dealerHand, playerHand) )
		{
			cout << "Player loses $" << bet << '.' << endl;
			purse -= bet;
		}
		else
		{
			if ( playerHand.isBlackjack() || playerHand.isFiveUnder() )
				bet *= 2;
			cout << "Player wins $" << bet << '.' << endl;
			purse += bet;
		}
	}
}