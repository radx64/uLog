#include "Flusher.hpp"
#include <sstream>

Flusher::Flusher(std::string prefix, IBuffer* buff) : prefix_(prefix), buff_(buff){}

Flusher::Flusher(Flusher&& f) : stream_(){}

Flusher::~Flusher()
{
    std::stringstream finalStream;
    finalStream << prefix_ << "\t"<< stream_.str() << "\n";
	(*buff_) << finalStream.str();
}
