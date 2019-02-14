// Tools.h

#include<string>

#ifndef TOOLS_LOCK
#define TOOLS_LOCK

namespace tools
{
	float getFloat(std::string prompt);
	int getInt(std::string prompt);
	int getPositiveInt(std::string prompt);
	int getNonNegativeInt(std::string prompt);
	char getChar(std::string prompt);
	std::string getString(std::string prompt);
	std::string getLine(std::string prompt);
	int getBoundedInt(std::string prompt, int lowBound, int highBound);
	bool getBool( std::string prompt );

	bool fail(std::string message);
	void pause(void);
	void flush(void);

	int width( int x );
	int larger( int a, int b );

}

#endif