#include "NetworkBuffer.hpp"

#include <string.h>
#include <unistd.h>

#include <chrono>
#include <iostream>

NetworkBuffer::NetworkBuffer(std::string ip, int port)
:running_(true)
{
    socketDescriptor_ = socket(AF_INET,SOCK_DGRAM,0);
    sockaddr_in server;
    server_.sin_family = AF_INET;
    server_.sin_port = htons(port);
    server_.sin_addr.s_addr = inet_addr(ip.c_str());
    networkThread_ = std::thread([this](){asyncSend();});
}

void NetworkBuffer::asyncSend()
{
    do
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mutex_.lock();
        while (!sendQueue_.empty())
        {
            char buffer[1024];
            std::string message = sendQueue_.front();
            strcpy(buffer, message.c_str());

            sendto(
                socketDescriptor_,
                buffer,
                message.size(),
                0,
                (struct sockaddr *)&server_,
                sizeof(server_)
            );
            sendQueue_.pop();
        }
        mutex_.unlock();
    } while (running_);
}

IBuffer& NetworkBuffer::operator<<(const std::string& in)
{
    mutex_.lock();
    sendQueue_.push(in);
    mutex_.unlock();
    return *this;
}


NetworkBuffer::~NetworkBuffer()
{
    running_ = false;
    networkThread_.join();
    close(socketDescriptor_);
}
