#include <iostream>
#include <sstream>

#include "Logger.hpp"

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

// Flusher FileLogger::debug(void)
// {
// 	return Flusher("[ DBG ] ", &buff_);
// }
// Flusher FileLogger::info(void)
// {
// 	return Flusher("[ INF ] ", &buff_);
// }
// Flusher FileLogger::warn(void)
// {
// 	return Flusher("[ WRN ] ", &buff_);
// }
// Flusher FileLogger::error(void)
// {
// 	return Flusher("[ ERR ] ", &buff_);
// }

Buffer Logger::buff_;
// FileBuffer FileLogger::buff_("log.txt");