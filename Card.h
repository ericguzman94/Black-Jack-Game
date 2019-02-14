// Card

#include<string>

#ifndef CARD_LOCK
#define CARD_LOCK

namespace card_space
{
	class Card
	{
	public:
		Card(void);
		int value(void);
		bool isAce(void);
		bool isFace(void);
		std::string name(void);
	private:
		int ID;
	};
}

#endif