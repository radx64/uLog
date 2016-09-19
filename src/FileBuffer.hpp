#include <fstream>

#include "IBuffer.hpp"

class FileBuffer : public IBuffer
{
public:
explicit FileBuffer(std::string fileName);

IBuffer& operator<<(const std::string& in) override;

~FileBuffer() override;

private:
std::fstream file_;
};
