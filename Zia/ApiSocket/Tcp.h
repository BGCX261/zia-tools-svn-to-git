#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Ws2tcpip.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include "BasicEndpoint.hpp"

namespace ip
{
	class Tcp
	{

	private:

		explicit Tcp(int family)
			: _family(family)
		{
		}

		int _family;

	public:

		static	Tcp	v4()
		{
			return Tcp(PF_INET);
		}

		static Tcp v6()
		{
			return Tcp(PF_INET6);
		}


		int		type() const
		{
			return SOCK_STREAM;
		}
		int		protocol() const
		{
			return IPPROTO_TCP;
		}
		int		family() const
		{
			return this->_family;
		}

		Tcp(const Tcp& other)
		{
			this->_family = other._family;
		}

		Tcp& operator=(Tcp const& other)
		{
			this->_family = other._family;
			return *this;
		}

		bool	operator==(Tcp const& other) const
		{
			return this->_family == other._family;
		}

		bool	operator!=(Tcp const& other) const
		{
			return !(*this == other);
		}
	};
}