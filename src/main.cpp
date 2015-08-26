#include "Logger.hpp"

int main()
{
	Logger l;
	l.debug() << "Hello World!" << " Some more greetings!";
	l.debug() << "This should be done in new line!";
	l.info()  << "And this is info print!";
	l.warn()  << "And this is warn print!";
	l.error()   << "And this is error print!";
	l.error()   << 12;
	l.error()   << 3.4;

	FileLogger fl;
	fl.debug() << "Hello World!" << " Some more greetings!";
	fl.debug() << "This should be done in new line!";
	fl.info()  << "And this is info print!";
	fl.warn()  << "And this is warn print!";
	fl.error()   << "And this is error print!";
	fl.error()   << 12;
	fl.error()   << 3.4;




	return 0;
}