#include "Flusher.hpp"
#include "FileBuffer.hpp"
#include "Logger.hpp"

class FileLogger : public Logger
{
public:
    FileLogger(){}

protected:
    virtual IBuffer* getBuffer() override;
    static FileBuffer buff_;
};
