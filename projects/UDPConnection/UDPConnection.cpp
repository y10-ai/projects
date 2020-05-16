/*******************************
    Yonatan Zaken
    File Name
    File Type
    //
    ILRD - RD8081               
*******************************/

#include <iostream> // cout
#include <unistd.h> // close
#include <cstring>  // memset
#include <cstdio>

extern "C"
{
    #include "socket.h"
}
#include "UDPConnection.hpp"

namespace ilrd
{

UDPConnection::UDPConnection():
    m_sockfd(GetUDPSocket())
{
}

/*****************************************************************************/

UDPConnection::~UDPConnection()
{
    close(m_sockfd);
}

/*****************************************************************************/

void UDPConnection::SendTo(const char *buffer) const
{
    if (-1 == (sendto(m_sockfd, buffer, strlen(buffer), 0,
    &m_sendToAddr, m_addrLen))) 
    {
        //throw
    }
}

/*****************************************************************************/

void UDPConnection::ReceiveFrom(char *buffer)
{
    if (-1 == (recvfrom(m_sockfd, buffer, BLOCK_SIZE - 1, 0, 
    &m_sendToAddr, &m_addrLen))) 
    {
        //throw
    }
}

/*****************************************************************************/

int UDPConnection::GetFD() const noexcept
{
    return m_sockfd;    
}

/*****************************************************************************/

int UDPConnection::GetUDPSocket()
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(addrinfo));
    struct addrinfo *servinfo = NULL;

    InitHints(&hints, AF_INET, SOCK_DGRAM, AI_PASSIVE);    
    
    int err_val = 0;
    if (0 != (err_val = getaddrinfo(NULL, "4443", &hints, &servinfo))) 
    {
        //throw
    }

    int sockfd = 0;
    if (-1 == (sockfd = GetInternetAddr(servinfo, SERVER)))
    {
        //throw
    }

    freeaddrinfo(servinfo);

    return sockfd;
}

} // namespace ilrd


