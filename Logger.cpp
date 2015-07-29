#include <iostream>
#include <sstream>

class Flusher
{
public:
	Flusher()
	{
	}	

	Flusher(Flusher&& f) : stream_()
	{
	}

	template <typename T>
	Flusher& operator<<(const T& in)
	{
		stream_ << in;
		return *this;
	}	

	~Flusher()
	{
		std::cout <<"[ DEBUG ] "<< stream_.str() <<std::endl;
	}

	std::stringstream stream_;
};

class Logger
{
public:
	Flusher debug(void)
	{
		return Flusher();
	}
};

int main()
{
	Logger l;
	l.debug() << "Hello World!" << " Some more greetings!";
	l.debug() << "This should be done in new line!";
	return 0;
}