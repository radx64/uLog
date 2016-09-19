#include <iostream>
#include <sstream>

#include "Logger.hpp"

Flusher Logger::debug()
{
	return Flusher("[ DBG ] ", getBuffer());
}
Flusher Logger::info()
{
	return Flusher("[ INF ] ", getBuffer());
}
Flusher Logger::warn()
{
	return Flusher("[ WRN ] ", getBuffer());
}
Flusher Logger::error()
{
	return Flusher("[ ERR ] ", getBuffer());
}

IBuffer* Logger::getBuffer()
{
    return &buff_;
}

Buffer Logger::buff_;
