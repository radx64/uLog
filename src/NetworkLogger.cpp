#include "NetworkLogger.hpp"

NetworkBuffer NetworkLogger::buff_("127.0.0.1", 12345);

IBuffer* NetworkLogger::getBuffer()
{
    return &buff_;
}
