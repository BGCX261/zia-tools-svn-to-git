#pragma once
#include "IAcceptor.h"
#include "SocketTCP.h"

namespace ip{
	namespace tcp{
		
		class AcceptorTcp :
			public ip::tcp::IAcceptor
		{

		private:
			ip::tcp::socket	_sock;

		public:
			AcceptorTcp(const ip::tcp::endpoint&);
			virtual ~AcceptorTcp(void);
			virtual void	accept(ip::tcp::socket& peer, ip::tcp::endpoint& peer_endpoint);
			virtual void	accept(ip::tcp::socket& peer);
			virtual const ip::tcp::socket&	socket() const;
			virtual ip::BasicEndpoint<ip::Tcp>	do_accept(SOCKET* socket, SOCKADDR*, int*);
			void	ip::tcp::AcceptorTcp::listen(int backlog);

		};
	};
};


