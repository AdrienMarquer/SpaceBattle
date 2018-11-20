#pragma once

#include "IClientSocket.hpp"

class IServerSocket {
public:
	class OnSocketEvent {
	public:
		virtual	~OnSocketEvent() {}
		virtual void	onNewConnection(IServerSocket *socket) = 0;
	};
	virtual ~IServerSocket(void) {}
	virtual void	createServer(int port, int queueSize) = 0;
	virtual void	closeServer() = 0;
	virtual void	setOnSocketEventListener(IServerSocket::OnSocketEvent *listener) = 0;
	virtual IClientSocket	*getNewClient() = 0;
	virtual bool			hasClientInQueue() const = 0;
	virtual boost::asio::io_service &getMService() = 0;

};
