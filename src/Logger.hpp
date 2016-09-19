#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <iostream>

#include "Buffer.hpp"
#include "Flusher.hpp"

class Logger
{
public:
	Flusher debug();
	Flusher info();
	Flusher warn();
	Flusher error();

protected:
    virtual IBuffer* getBuffer();
	static Buffer buff_;
};
#endif  // LOGGER_HPP_
