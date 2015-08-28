#ifndef FLUSHER_HPP
#define FLUSHER_HPP

#include <sstream>

#include "IBuffer.hpp"

class Flusher
{
public:
	Flusher(std::string prefix, IBuffer* buff);

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
	IBuffer* buff_;
};

#endif // FLUSHER_HPP