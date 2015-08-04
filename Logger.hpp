#include <iostream>
#include <sstream>

class Buffer
{
public:
	explicit Buffer();

	template <typename T>
	Buffer& operator<<(const T& in)
	{
		std::cout << in;
		return *this;
	}	

	~Buffer();
};

class Flusher
{
public:
	Flusher(std::string prefix, Buffer* buff);

	Flusher(Flusher&& f);

	template <typename T>
	Flusher& operator<<(const T& in)
	{
	stream_ << in;
	return *this;
	}	

	~Flusher();

	std::stringstream stream_;
	std::string prefix_;
	Buffer* buff_;
};


class Logger
{
public:
	Flusher debug(void);
private:
	static Buffer buff_;
};