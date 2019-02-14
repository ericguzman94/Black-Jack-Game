// Card.cpp

#include"Card.h"
#include<string>
using namespace std;

namespace card_space
{
	const int INITIAL_ACE_VALUE = 11;
	const int FACE_VALUE = 10;

	Card::Card(void)
	{
		ID = 1 + rand() % 13;
	}

	int Card::value(void)
	{
		if ( isAce() )
			return INITIAL_ACE_VALUE;
		if ( isFace() )
			return FACE_VALUE;
		return ID;
	}

	bool Card::isAce(void)
	{
		return ID == 1;
	}

	bool Card::isFace(void)
	{
		return ID > 10;
	}

	string Card::name(void)
	{
		switch (ID)
		{
		case 1: return "Ace";
		case 2: return "Two";
		case 3: return "Three";
		case 4: return "Four";
		case 5: return "Five";
		case 6: return "Six";
		case 7: return "Seven";
		case 8: return "Eight";
		case 9: return "Nine";
		case 10: return "Ten";
		case 11: return "Jack";
		case 12: return "Queen";
		case 13: return "King";
		}
		return "Unknown";
	}

}