#pragma once


#include <Ws2tcpip.h>

#include <sstream>
#include <string>
#include "Address.h"
#include "socketType.hpp"

namespace ip{

	template<typename InternetProtocol>
	class BasicEndpoint
	{
	private:
		InternetProtocol _protocol;
		SOCKADDR_IN		 _base;

	public:
		BasicEndpoint(void)
			: _protocol(InternetProtocol::v4())
		{
			this->_base.sin_family = _protocol.family();
			this->_base.sin_port = htons(0);
			this->_base.sin_addr = ip::Address::any().data();
		}

		~BasicEndpoint(void)
		{

		}

		BasicEndpoint(const InternetProtocol& protocol, unsigned short port = 0)
			: _protocol(protocol)
		{
			this->_base.sin_port = htons(port);
			this->_base.sin_family = _protocol.family();
			this->_base.sin_addr = ip::Address::any().data();
		}

		BasicEndpoint(const ip::Address& addr, unsigned short port = 0)
			: _protocol(InternetProtocol::v4())
		{
			this->_base.sin_port = htons(port);
			this->_base.sin_family = _protocol.family();
			this->_base.sin_addr = addr.data();
		}

		BasicEndpoint(const BasicEndpoint<InternetProtocol>& other)
			: _protocol(other._protocol), _base(other._base)
		{

		}

		BasicEndpoint<InternetProtocol>& operator=(const BasicEndpoint<InternetProtocol>& other)
		{
			this->_protocol = other._protocol;
			this->_base = other._base;
			return *this;
		}

		BasicEndpoint<InternetProtocol>& operator=(SOCKADDR_IN base)
		{
			this->_base = base;
			return *this;
		}

		SOCKADDR_IN&	ref_data()
		{
			return this->_base;
		}

		const SOCKADDR_IN&	ref_data() const
		{
			return this->_base;
		}

		SOCKADDR_IN* data()
		{
			return  &this->_base;
		}

		const SOCKADDR_IN* data() const
		{
			return &this->_base;
		}


		unsigned short	port() const
		{
			return ntohs(this->_base.sin_port);
		}

		std::string		portToString() const
		{
			std::ostringstream oss;
			oss << this->port();
			std::string port = oss.str();
			return port;
		}

		ip::Address	address() const
		{
			return ip::Address(this->_base.sin_addr.s_addr);
		}

		void	address(const ip::Address& addr)
		{
			this->_base.sin_addr.s_addr = addr.toUlong();
		}

		size_t	size() const
		{
			return sizeof(this->_base);
		}


		bool	isV4() const
		{
			return this->_base.sa_family == AF_INET;
		}

		bool	isV6() const
		{
			return this->_base.sa_family == AF_INET6;
		}

		bool	operator==(const ip::BasicEndpoint<InternetProtocol>& addr) const
		{
			return this->_base == addr._base && this->_protocol == addr._protocole;
		}

		bool	operator!=(const ip::BasicEndpoint<InternetProtocol>& addr) const
		{
			return !(*this == addr):
		}
		bool	operator<(const ip::BasicEndpoint<InternetProtocol>& addr) const
		{
			return this->_base.sin_addr.s_addr < addr._base.sin_addr.s_addr;
		}

		bool	operator>(const ip::BasicEndpoint<InternetProtocol>& addr) const
		{
			return !(*this < addr);
		}


		const InternetProtocol&	protocole_type() const
		{
			return _protocol;
		}
	};
};