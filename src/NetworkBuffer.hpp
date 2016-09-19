#include <fstream>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "IBuffer.hpp"

class NetworkBuffer : public IBuffer
{
public:
explicit NetworkBuffer(std::string ip, int port);

IBuffer& operator<<(const std::string& in) override;

~NetworkBuffer() override;

private:
    int socketDescriptor_;
    sockaddr_in server_;
};
