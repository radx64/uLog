#include "Buffer.hpp"
#include <iostream>

Buffer::Buffer(){}

Buffer::~Buffer(){}

IBuffer& Buffer::operator<<(const std::string& in)
{
	std::cout << in;
	return *this;
}

