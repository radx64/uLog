#include <iostream>
#include <sstream>

#include "Logger.hpp"

Buffer::Buffer()
{
	// std::cout << "CTOR - Buffer created!" <<  std::endl;
}

Buffer::~Buffer()
{
	// std::cout << "DTOR - Buffer destroyed!" <<  std::endl;
}

Flusher::Flusher(std::string prefix, Buffer* buff) : prefix_(prefix), buff_(buff)
{
}

Flusher::Flusher(Flusher&& f) : stream_()
{
}

Flusher::~Flusher()
{
	(*buff_) << prefix_ << "\t"<< stream_.str() << "\n";
}


Flusher Logger::debug(void)
{
	return Flusher("[ DBG ] ", &buff_);
}

Flusher Logger::info(void)
{
	return Flusher("[ INF ] ", &buff_);
}
Flusher Logger::warn(void)
{
	return Flusher("[ WRN ] ", &buff_);
}
Flusher Logger::error(void)
{
	return Flusher("[ ERR ] ", &buff_);
}
Buffer Logger::buff_;