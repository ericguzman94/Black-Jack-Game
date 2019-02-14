// Tools.cpp

#include<iostream>
#include<string>
#include"Tools.h"
using namespace std;

namespace tools
{
	int larger( int a, int b )
	{
		return ( a > b ) ? a : b;
	}

	int width( int x )
	{
		int spaceNeededSoFar = 0;

		if ( x < 0 )
		{
			++spaceNeededSoFar;
			x = -x;
		}

		while ( x >= 10 )
		{
			x /= 10; // remove a digit
			++spaceNeededSoFar;
		}

		++spaceNeededSoFar; // for the last digit

		return spaceNeededSoFar;
	}

	void pause(void)
	{
		cout << "press enter to finish...";
		cin.ignore(999,'\n');
	}

	void flush(void)
	{
		cin.ignore(999,'\n');
	}

	int getPositiveInt(string prompt)
	{
		return getBoundedInt(prompt, 1, INT_MAX);
	}

	int getNonNegativeInt(string prompt)
	{
		return getBoundedInt(prompt, 0, INT_MAX);
	}

	int getBoundedInt(string prompt, int lowBound, int highBound)
	{
		if ( lowBound > highBound )
		{
			cout << "unacceptable bounds" << endl;
			throw 1;
		}
		do
		{
			int userInput = getInt(prompt);
			if ( userInput >= lowBound && userInput <= highBound )
				return userInput;
			cout << "Input must be in the range "
				<< lowBound
				<< " to "
				<< highBound
				<< "."
				<< endl;
		} while (true);
	}

	float getFloat( string prompt )
	{
		float userInput;
		do
		{
			cout << prompt;
			cin >> userInput;
			flush();

		} while ( fail("Bad float input.") );

		return userInput;
	}

	bool fail(string message)
	{
		if ( !cin.fail() )
			return false;
		cin.clear();
		flush();
		cout << message << endl;
		return true;
	}

	int getInt( string prompt )
	{

		int userInput;

		do
		{
			cout << prompt;
			cin >> userInput;
			flush();
			// other loop controls
			// break; exit loop now
			// continue; go to condition now

		} while ( fail("Bad integer input.") );

		return userInput;
	}

#ifdef ALTERNATE_LOOP
		do
		{
			int userInput;
			cout << prompt;
			cin >> userInput;
			flush();
			if ( !cin.fail() ) return userInput;
			cin.clear();
			flush();
			cout << "bad person!" << endl;

		} while (true);
#endif


	string getString( string prompt )
	{
		string userInput;
		do
		{
			cout << prompt;
			cin >> userInput;
			flush();
		} while ( fail("Bad string input.") );

		return userInput;
	}

	string getLine( string prompt )
	{
		string userInput;
		do
		{
			getline( cin, userInput );
		} while ( fail("Bad line input.") );

		return userInput;
	}

	bool getBool( string prompt )
	{
		do
		{
			char userInput = getChar(prompt);
			switch ( userInput )
			{
			case 'y': case 'Y': return true;
			case 'n': case 'N': return false;
			}
			cout << "Please enter y or n." << endl;

		} while (true);
	}

	char getChar( string prompt )
	{
		char userInput;

		do
		{
			cout << prompt;
			cin >> userInput;
			flush();
		} while ( fail("Bad char input.") );

		return userInput;
	}
}