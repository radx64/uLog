#include "Flusher.hpp"
#include "NetworkBuffer.hpp"
#include "Logger.hpp"

class NetworkLogger : public Logger
{
public:
    NetworkLogger(){}

protected:
    virtual IBuffer* getBuffer() override;
    static NetworkBuffer buff_;
};
