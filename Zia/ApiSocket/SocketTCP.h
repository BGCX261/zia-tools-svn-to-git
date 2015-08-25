#pragma once

#include <string>
#include <vector>

#include "CountObject.h"
#include "Endpoint.h"
#include "Tcp.h"
#include "SocketOption.h"
#include "IVisitByAcceptor.h"
#include "Address.h"

namespace ip{
	namespace tcp{

		class SocketTCP
			: public CountObject, public ip::detail::IVisitByAcceptor
		{

		private:

			ip::tcp::endpoint	_localEnpoint;
			ip::tcp::endpoint	_remoteEndpoint;
			SOCKET				_socket;
			static int			pending;
			void				accept(ip::tcp::IAcceptor& server);


		public:

			SocketTCP();
			SocketTCP(const ip::tcp::endpoint&);
			SocketTCP(const SocketTCP&);
			SocketTCP(SOCKET fd);
			virtual ~SocketTCP();

			SocketTCP&	operator=(const SocketTCP& socket);
			enum shutdownType
			{
				SHUT_RECEIVE = 0,
				SHUT_SEND,
				SHUT_BOTH
			};

			const ip::tcp::endpoint&	local() const;
			const ip::tcp::endpoint&	remote() const;
			void   local(const ip::tcp::endpoint&);
			void  remote(const ip::tcp::endpoint&);

			SOCKET	native();

			int		open(const ip::Tcp& protocol = ip::Tcp::v4());
			bool	connect(const ip::tcp::endpoint& remote);
			bool	close();
			bool	shutDown(ip::tcp::SocketTCP::shutdownType how);
			bool	isOpen() const;

			int		avaible() const;
			template<typename SettableOption>
			int		setOption(SettableOption& opt)
			{
				int a = ::setsockopt(this->_socket, opt.level(), opt.name(), reinterpret_cast<char*>(opt.data()), opt.size());
				if (a == SOCKET_ERROR)
					throw (NetWorkExeption(NetWorkExeption::From::CONNECT, strerror(SOCKET_ERROR), NetWorkExeption::Medium));
				return a; 
			}

			template<typename GettableOption>
			int		getOption(GettableOption& opt) const
			{
				int iOptVal = opt.value();
				int iOptLen = opt.size();
				int c = ::getsockopt(this->_socket, opt.level(), opt.name(), reinterpret_cast<char*>(&iOptVal), &iOptLen); 
				opt = GettableOption(iOptVal);
				return c;
			}

			bool	bind(const ip::tcp::endpoint& endpoint);
			int		send(const std::string&) const;
			int		send(const char*, size_t) const;
			int		send(const std::vector<char>&) const;

			int		recv(char*, size_t);
			int		recv(std::string&);
			int		recv(std::vector<char>&);

			static	int	maxConnections();
			static	void maxConnections(int);

			virtual	void	access(ip::tcp::IAcceptor& acceptor);
			virtual	void	access(ip::tcp::IAcceptor& acceptor, ip::tcp::endpoint);
		};

		typedef	ip::tcp::SocketTCP socket;
	};
};