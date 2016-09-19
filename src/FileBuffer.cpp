#include "FileBuffer.hpp"

FileBuffer::FileBuffer(std::string fileName)
{
    file_.open(fileName, std::fstream::out);
}

IBuffer& FileBuffer::operator<<(const std::string& in)
{
    file_ << in;
    return *this;
}

FileBuffer::~FileBuffer()
{
    file_.close();
};
