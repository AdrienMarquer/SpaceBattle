#pragma once

#include "IServerSocket.hpp"

#include <list>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace boost::asio::ip;

class TcpServer : public IServerSocket, private boost::noncopyable
{
    public:
        TcpServer();
        ~TcpServer();
        TcpServer(const TcpServer &) = delete;
        const TcpServer & operator = (const TcpServer &) = delete;
        void            createServer(int port, int queueSize);
        void            closeServer();
        void            setOnSocketEventListener(IServerSocket::OnSocketEvent *listener);
        IClientSocket*  getNewClient();
        bool            hasClientInQueue() const;

    boost::asio::io_service &getMService() ;

    void startAccept(void);

        boost::asio::io_service                     mService;
private:
        boost::asio::signal_set                     mSigset;
        boost::shared_ptr<tcp::acceptor>            mAcceptor;
        std::list<tcp::socket*>                     mSockets;
        IServerSocket::OnSocketEvent*               mListener;
        int                                         mPort;
};
