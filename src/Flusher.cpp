#include "Flusher.hpp"

Flusher::Flusher(std::string prefix, IBuffer* buff) : prefix_(prefix), buff_(buff){}

Flusher::Flusher(Flusher&& f) : stream_(){}

Flusher::~Flusher()
{
	(*buff_) << prefix_ << "\t"<< stream_.str() << "\n";
}