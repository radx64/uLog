#include <iostream>
#include <sstream>

class Flusher
{
public:
	Flusher(std::string prefix) : prefix_(prefix)
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
		std::cout <<"[ DEBUG ] " << prefix_ << " - "<< stream_.str() <<std::endl;
	}

	std::stringstream stream_;
	std::string prefix_;
};

class Buffer
{
public:
	explicit Buffer()
	{
		std::cout << "CTOR - Buffer created!" <<  std::endl;
	}

	~Buffer()
	{
		std::cout << "DTOR - Buffer destroyed!" <<  std::endl;
	}

};

class Logger
{
public:
	Flusher debug(void)
	{
		return Flusher("Prefix");
	}
private:
	static Buffer buff_;
};

Buffer Logger::buff_;

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