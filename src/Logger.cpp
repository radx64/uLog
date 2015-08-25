#include <iostream>
#include <sstream>

#include "Logger.hpp"

Buffer::Buffer()
{
	std::cout << "CTOR - Buffer created!" <<  std::endl;
}

Buffer::~Buffer()
{
	std::cout << "DTOR - Buffer destroyed!" <<  std::endl;
}

Flusher::Flusher(std::string prefix, Buffer* buff) : prefix_(prefix), buff_(buff)
{
}

Flusher::Flusher(Flusher&& f) : stream_()
{
}

Flusher::~Flusher()
{
	(*buff_) <<"[ DEBUG ] " << prefix_ << " - "<< stream_.str() << "\n";
}


Flusher Logger::debug(void)
{
	return Flusher("Prefix", &buff_);
}

Buffer Logger::buff_;