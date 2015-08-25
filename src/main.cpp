#include "Logger.hpp"

int main()
{
	Logger l;
	l.debug() << "Hello World!" << " Some more greetings!";
	l.debug() << "This should be done in new line!";
	l.info()  << "And this is info print!";
	l.warn()  << "And this is warn print!";
	l.error()   << "And this is error print!";
	Logger l2;
	Logger l3;
	Logger l4;
	return 0;
}