#include <chrono>
#include <cstdint>

#include "Logger.hpp"
#include "FileLogger.hpp"
#include "NetworkLogger.hpp"

int main()
{
	Logger l;
	l.debug() << "Hello World!" << " Some more greetings!";
	l.debug() << "This should be done in new line!";
	l.info()  << "And this is info print!";
	l.warn()  << "And this is warn print!";
	l.error() << "And this is error print!";
	l.error() << 12;
	l.error() << 3.4;

	FileLogger fl;
	fl.debug() << "Hello World!" << " Some more greetings!";
	fl.debug() << "This should be done in new line!";
	fl.info()  << "And this is info print!";
	fl.warn()  << "And this is warn print!";
	fl.error() << "And this is error print!";
	fl.error() << 12;
	fl.error() << 3.4;

	NetworkLogger nl;
	nl.debug() << "Hello World!" << " Some more greetings!";
	nl.debug() << "This should be done in new line!";
	nl.info()  << "And this is info print!";
	nl.warn()  << "And this is warn print!";
	nl.error() << "And this is error print!";
	nl.error() << 12;
	nl.error() << 3.4;


	for (uint32_t i = 0; i <= 1024; ++i)
	{
		//l.error()  << i;
		//fl.error() << i;
		nl.error() << i;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}


	return 0;
}
