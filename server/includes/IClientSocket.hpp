#pragma once

#include <boost/asio.hpp>
#include <string>

using namespace boost::asio::ip;

class IClientSocket {
public:
	class OnSocketEvent {
	public:
		virtual	~OnSocketEvent() {}
		virtual	void	onBytesWritten(IClientSocket *socket, unsigned int nbBytes) = 0;
		virtual void	onSocketReadable(IClientSocket *socket, std::string &cmd) = 0;
		virtual void	onSocketClosed(IClientSocket *socket) = 0;
	};
	virtual ~IClientSocket(void) {}
	virtual void	connect(const std::string &addr, int port) = 0;
	virtual void	initFromSocket(void *socket) = 0;
	virtual	void	closeClient(void) = 0;
	virtual unsigned int	nbBytesToRead(void) const = 0;
	virtual std::string getRemoteIp() const = 0;
	virtual tcp::socket *getMSocket() const = 0;
	virtual void	setOnSocketEventListener(IClientSocket::OnSocketEvent *listener) = 0;

};
