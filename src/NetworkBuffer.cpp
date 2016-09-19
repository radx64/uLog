#include "NetworkBuffer.hpp"

#include <string.h>
#include <unistd.h>

#include <iostream>

NetworkBuffer::NetworkBuffer(std::string ip, int port)
{
    socketDescriptor_ = socket(AF_INET,SOCK_DGRAM,0);
    sockaddr_in server;
    server_.sin_family = AF_INET;
    server_.sin_port = htons(port);
    server_.sin_addr.s_addr = inet_addr(ip.c_str());
}

IBuffer& NetworkBuffer::operator<<(const std::string& in)
{
    char buffer[1024];
    strcpy(buffer, in.c_str());

    sendto(
        socketDescriptor_,
        buffer,
        in.size(),
        0,
        (struct sockaddr *)&server_,
        sizeof(server_)
    );
}

NetworkBuffer::~NetworkBuffer()
{
    close(socketDescriptor_);
}
