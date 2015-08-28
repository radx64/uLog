#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "IBuffer.hpp"

class Buffer : public IBuffer
{
public:
	explicit Buffer();

	// template <typename T>
	// IBuffer& operator<<(const T& in) override
	// {
	// 	std::cout << in;
	// 	return *this;
	// }	

	IBuffer& operator<<(const std::string& in) override;

	~Buffer() override;
};

#endif // BUFFER_HPP