// Hand.cpp

#include"Hand.h"

namespace hand_space
{
	const int MAX_TOTAL = 21;
	const int HIGH_ACE_VALUE = 11;
	const int LOW_ACE_VALUE = 1;

	Hand::Hand(void)
	{
		total = 0;
		count = 0;
		countOfHighAces = 0;
	}

	void Hand::addCard(card_space::Card card)
	{
		total += card.value();
		++count;
		if ( card.isAce() )
			++countOfHighAces;

		// if below?
		while ( total > MAX_TOTAL && countOfHighAces > 0 )
		{
			total -= HIGH_ACE_VALUE - LOW_ACE_VALUE;
			--countOfHighAces;
		}
	}

	int Hand::value(void)
	{
		return total;
	}

	bool Hand::isBlackjack(void)
	{
		return total==MAX_TOTAL && count==2;
	}

	bool Hand::isFiveUnder(void)
	{
		return total<=MAX_TOTAL && count>=5;
	}

	bool Hand::isBusted(void)
	{
		return total > MAX_TOTAL;
	}
	
}