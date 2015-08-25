#include "SocketTCP.h"
#include "NetWorkExeption.h"
#include "IAcceptor.h"
#include <iostream>

int	ip::tcp::SocketTCP::pending = 50;

ip::tcp::SocketTCP::SocketTCP()
	: CountObject(), _socket(INVALID_SOCKET)
{

}

ip::tcp::SocketTCP::SocketTCP(const ip::tcp::endpoint& endpoint)
	: CountObject(), _socket(INVALID_SOCKET)
{
	this->open(endpoint.protocole_type());
	this->bind(endpoint);
}

ip::tcp::SocketTCP::SocketTCP(const ip::tcp::SocketTCP& other)
	: CountObject(), _localEnpoint(other._localEnpoint), _remoteEndpoint(other._remoteEndpoint), _socket(other._socket)
{

}

ip::tcp::SocketTCP::SocketTCP(SOCKET fd)
{
	this->_socket = fd;
}


ip::tcp::SocketTCP::~SocketTCP()
{

}

bool	ip::tcp::SocketTCP::shutDown(ip::tcp::SocketTCP::shutdownType how)
{
	if (::shutdown(this->_socket, how) == SOCKET_ERROR)
		throw (NetWorkExeption(NetWorkExeption::SHUT, GetLastError(), NetWorkExeption::Low));
	return true;
}

bool	ip::tcp::SocketTCP::close()
{
	if (::closesocket(this->_socket) == SOCKET_ERROR)
		throw (NetWorkExeption(NetWorkExeption::CLOSE, GetLastError(), NetWorkExeption::Medium));
	this->_socket = INVALID_SOCKET;
	return true;
}

bool	ip::tcp::SocketTCP::bind(const ip::tcp::endpoint& endpoint)
{
	int c = ::bind(this->_socket, (SOCKADDR*)(endpoint.data()), endpoint.size());
	if (c == -1)
		throw (NetWorkExeption(NetWorkExeption::BIND, GetLastError(), NetWorkExeption::Medium));
	this->_localEnpoint = endpoint;
	return true;
}

int	ip::tcp::SocketTCP::open(const Tcp& protocol)
{
	this->_socket = ::socket(protocol.family(), protocol.type(), protocol.protocol());
	if (this->_socket == SOCKET_ERROR)
		throw (NetWorkExeption(NetWorkExeption::SOCK, GetLastError(), NetWorkExeption::Hight));
	return this->_socket;
}

bool	ip::tcp::SocketTCP::connect(const ip::tcp::endpoint& remote)
{
	if (!this->isOpen())
		this->open(ip::Tcp::v4());
	if(::connect(this->_socket, reinterpret_cast<const SOCKADDR*>(remote.data())
		,remote.size()) == SOCKET_ERROR)	
		throw (NetWorkExeption(NetWorkExeption::CONNECT, GetLastError(), NetWorkExeption::Medium));
	this->_remoteEndpoint = remote;
	return true;
}

int		ip::tcp::SocketTCP::send(const std::string& buffer) const
{
	return ::send(this->_socket , buffer.data(), buffer.size(), 0);
}

int		ip::tcp::SocketTCP::send(const char* buffer, size_t size) const
{
	return ::send(this->_socket , buffer, size, 0);
}
int		ip::tcp::SocketTCP::send(const std::vector<char>& buffer) const
{
	return ::send(this->_socket, buffer.data(), buffer.size(), 0);
}

int		ip::tcp::SocketTCP::recv(char* buffer, size_t size)
{
	return ::recv(this->_socket, buffer, size, 0);
}

int		ip::tcp::SocketTCP::recv(std::string& buffer)
{
	int s = ::recv(this->_socket, &buffer[0], buffer.size() - 1, 0);
	return s;
}

int		ip::tcp::SocketTCP::recv(std::vector<char>& buffer)
{
	return ::recv(this->_socket, &buffer[0], buffer.size(), 0);
}

int	ip::tcp::SocketTCP::maxConnections()
{
	return ip::tcp::SocketTCP::pending;
}

void ip::tcp::SocketTCP::maxConnections(int max)
{
	ip::tcp::SocketTCP::pending = max;
}

bool ip::tcp::SocketTCP::isOpen() const
{
	return this->_socket != INVALID_SOCKET;
}

int	ip::tcp::SocketTCP::avaible() const
{
	unsigned long iMode = 0;
	ioctlsocket(this->_socket, FIONREAD, &iMode);
	return iMode;
}

const ip::tcp::endpoint&	ip::tcp::SocketTCP::local() const
{
	return this->_localEnpoint;
}
const ip::tcp::endpoint&	ip::tcp::SocketTCP::remote() const
{
	return this->_remoteEndpoint;
}
void	ip::tcp::SocketTCP::local(const ip::tcp::endpoint& local)
{
	this->_localEnpoint = local;
}
void	ip::tcp::SocketTCP::remote(const ip::tcp::endpoint& remote)
{
	this->_remoteEndpoint = remote;
}

SOCKET	ip::tcp::SocketTCP::native()
{
	return this->_socket;
}

void	ip::tcp::SocketTCP::access(ip::tcp::IAcceptor& acceptor)
{
	SOCKADDR_IN	peer;
	::memset(&peer, 0, sizeof(peer));
	int	dataSize = sizeof(peer);
	acceptor.do_accept(&this->_socket, reinterpret_cast<SOCKADDR*>(&peer), &dataSize);
	this->_localEnpoint = acceptor.socket().local();
	this->_remoteEndpoint = peer;
}

void	ip::tcp::SocketTCP::access(ip::tcp::IAcceptor& acceptor, ip::tcp::endpoint)
{
	this->access(acceptor);
}

ip::tcp::SocketTCP&	ip::tcp::SocketTCP::operator=(const SocketTCP& other)
{
	this->_localEnpoint = other._localEnpoint;
	this->_remoteEndpoint = other._remoteEndpoint;
	this->_socket = other._socket;
	return *this;
}