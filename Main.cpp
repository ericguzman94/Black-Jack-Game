// Jim Hester
// Example 08 - blackjack

#include<iostream>
#include"Tools.h"
#include<time.h>
#include"Blackjack.h"
using namespace black_jack;
using namespace tools;
using namespace std;

int main(void)
{
	srand(time(0));
	try
	{
		blackjack();
	}
	catch (int exception)
	{
		cout << "Program Terminating" << endl;
		pause();
		return exception;
	}

	cout << endl;
	//pause();
	return 0;
}
