#pragma once

#include "IClientSocket.hpp"

#include <list>
#include <deque>
#include <vector>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/thread/mutex.hpp>

using namespace boost::asio::ip;

class TcpClient : public IClientSocket, private boost::noncopyable
{
public:
    TcpClient();
    ~TcpClient();
private:
    TcpClient(const TcpClient &) = delete;
    const TcpClient & operator = (const TcpClient &) = delete;

public:
    void            connect(const std::string &addr, int port);
    void            initFromSocket(void *socket);
    void            closeClient();
    unsigned int    nbBytesToRead() const;


private:
    void            startRecv();
    void            setOnSocketEventListener(IClientSocket::OnSocketEvent *listener);
    std::string getRemoteIp() const;
    static const int    BUFFER_SIZE = 1024;
    tcp::socket *getMSocket() const;
private:
    boost::asio::io_service                 mIOservice;
    tcp::socket*                            mSocket;
    char                                    mReadBuffer[BUFFER_SIZE];
    std::vector<char>                       mBuffer;
    IClientSocket::OnSocketEvent*           mListener;

};
