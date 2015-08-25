#include "AcceptorTcp.h"
#include "NetWorkExeption.h"

ip::tcp::AcceptorTcp::AcceptorTcp(const ip::tcp::endpoint& endpoint)
	: _sock(endpoint)
{
}


ip::tcp::AcceptorTcp::~AcceptorTcp(void)
{
}

void	ip::tcp::AcceptorTcp::accept(ip::tcp::socket& peer)
{
	peer.access(*this);

}

void	ip::tcp::AcceptorTcp::accept(ip::tcp::socket& peer, ip::tcp::endpoint& peer_endpoint)
{
	peer.access(*this, peer_endpoint);
}


void	ip::tcp::AcceptorTcp::listen(int backlog)
{
	try
	{
		int check = ::listen(this->_sock.native(), this->_sock.maxConnections());
		if (check == -1)
			throw (NetWorkExeption(NetWorkExeption::LISTEN, GetLastError(), NetWorkExeption::Medium));
	}
	catch (const NetWorkExeption&)
	{
		this->_sock.maxConnections(this->_sock.maxConnections() - 1);
		return this->listen(50);
	}
}



ip::BasicEndpoint<ip::Tcp>	ip::tcp::AcceptorTcp::do_accept(SOCKET* client, SOCKADDR* addr, int* addrlen)
{
	this->listen(50);
	*client = ::accept(this->_sock.native(), addr, addrlen);
	if (*client == SOCKET_ERROR)
		throw (NetWorkExeption(NetWorkExeption::ACCEPT, GetLastError(), NetWorkExeption::Medium));
	ip::tcp::endpoint remote;
	return remote;	 
}

const ip::tcp::socket&	ip::tcp::AcceptorTcp::socket() const
{
	return this->_sock;
}