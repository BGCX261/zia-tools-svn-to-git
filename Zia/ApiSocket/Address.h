#pragma once

#include <vector>
#include <string>

#ifndef WINSOCK2_NODEFINE
#define WINSOCK2_NODEFINE

#include <Ws2tcpip.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#endif

namespace ip{

	class Address
	{

	private:
		typedef std::vector<unsigned char> bytes_type;

		IN_ADDR		_addr;

	public:
		Address(void);
		explicit Address(unsigned long);
		explicit Address(const bytes_type&);
		Address(const Address&);
		Address& operator=(const Address& other);
		~Address(void);

		bool	isClassA() const;
		bool	isClassB() const;
		bool	isClassC() const;

		bool ip::Address::operator==(const Address& addr);
		bool ip::Address::operator!=(const Address& addr);
		bool ip::Address::operator<(const Address& addr);
		bool ip::Address::operator>(const Address& addr);

		static Address broadcast();
		static Address broadcast(const Address & addr, const Address & mask);
		static Address fromString(const std::string & str);
		static Address loopBack();
		static Address	netmask(const Address&);
		static Address	any();

		std::string		toString() const;
		unsigned long	toUlong() const;
		IN_ADDR			data() const;
	};
};
