#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "IBuffer.hpp"

class Buffer : public IBuffer
{
public:
	explicit Buffer();

	IBuffer& operator<<(const std::string& in) override;

	~Buffer() override;
};

#endif // BUFFER_HPP
