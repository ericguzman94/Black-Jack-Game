// Blackjack.h

#include"Hand.h"
#include<string>

#ifndef BLACKJACK_LOCK
#define BLACKJACK_LOCK

namespace black_jack
{
	void blackjack(void);
	void playGames(void);
	void playGame(void);
	void setUpPurse(int &purse);
	void processHands(int &purse);
	void playHand(int &purse);
	void bet(int purse, int&bet);
	void dealHand(hand_space::Hand &dealerHand, hand_space::Hand &playerHand);
	void dealInitialCards(hand_space::Hand &dealerHand, hand_space::Hand &playerHand);
	void dealPlayerHits(hand_space::Hand &playerHand);
	void dealDealerHits(hand_space::Hand &dealerHand);
	bool dealerWins(hand_space::Hand dealerHand, hand_space::Hand playerHand);
	void dealCard(hand_space::Hand &hand, std::string who, bool faceUp);
	void settleBet(hand_space::Hand dealerHand, hand_space::Hand playerHand, int bet, int &purse);
}

#endif