#include <fstream>
#include <queue>
#include <thread>
#include <mutex>

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
    void asyncSend();
    
    std::queue<std::string> sendQueue_;
    std::thread networkThread_;
    std::mutex mutex_;
    int socketDescriptor_;
    sockaddr_in server_;
    bool running_;

};
