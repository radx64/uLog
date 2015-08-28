#ifndef IBUFFER_HPP
#define IBUFFER_HPP
#include <string>

class IBuffer
{
public:
	virtual IBuffer& operator<<(const std::string& in) = 0;
	virtual ~IBuffer() {};
};
#endif // IBUFFER_HPP