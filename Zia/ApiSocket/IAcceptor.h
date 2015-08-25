#pragma once

#include "BasicEndpoint.hpp"
#include "SocketTCP.h"

namespace ip{

	class Tcp;

	namespace tcp{

		class SocketTCP;		

		class IAcceptor
		{
		public:
			virtual void	accept(ip::tcp::SocketTCP& peer, ip::BasicEndpoint<ip::Tcp>& peer_endpoint) = 0;
			virtual void	accept(ip::tcp::SocketTCP& peer) = 0;
			virtual ip::BasicEndpoint<ip::Tcp>	do_accept(SOCKET* socket, SOCKADDR*, int*) = 0;
			virtual const  ip::tcp::SocketTCP&	socket() const = 0;
		};
	};
};