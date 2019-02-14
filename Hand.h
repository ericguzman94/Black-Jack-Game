// Hand.h

#include"Card.h"

#ifndef HAND_LOCK
#define HAND_LOCK

namespace hand_space
{
	class Hand
	{
	public:
		Hand(void);
		void addCard(card_space::Card card);
		int value(void);
		bool isBlackjack(void);
		bool isFiveUnder(void);
		bool isBusted(void);
	private:
		int total;
		int count;
		int countOfHighAces;
	};
}

#endif