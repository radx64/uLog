#include "Logger.hpp"

int main()
{
	Logger l;
	l.debug() << "Hello World!" << " Some more greetings!";
	l.debug() << "This should be done in new line!";
	Logger l2;
	Logger l3;
	Logger l4;
	return 0;
}