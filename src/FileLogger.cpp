#include "FileLogger.hpp"

FileBuffer FileLogger::buff_("log.txt");

IBuffer* FileLogger::getBuffer()
{
    return &buff_;
}
