#include "Address.h"
#include <exception>
#include <sys/types.h>
#include <iostream>



ip::Address::Address(void)
{
	_addr.s_addr = 0;
}

ip::Address::Address(unsigned long addr)
{
	#if ULONG_MAX > 0xFFFFFFFF
		if (addr > 0xFFFFFFFF)
			throw std::execption("address_v4 from unsigned long");
	#endif // ULONG_MAX > 0xFFFFFFFF
	this->_addr.s_addr = addr;
}


ip::Address::Address(const bytes_type&	bytes)
{
	#if UCHAR_MAX > 0xFF
		if (bytes[0] > 0xFF || bytes[1] > 0xFF || bytes[2] > 0xFF || bytes[3] > 0xFF)
				throw std::execption("address_v4 from unsigned long");
	#endif // UCHAR_MAX > 0xFF
	std::copy(bytes.begin(), bytes.begin() + 4, &this->_addr.s_addr);
}

ip::Address::~Address()
{

}

ip::Address::Address(const ip::Address& other)
{
	this->_addr = other._addr;
}

bool ip::Address::isClassA() const
{
	unsigned long s = this->toUlong();
	return s >= 0x00000000 && s <= 	0x7FFFFFFF;
}

bool ip::Address::isClassB() const
{
	unsigned long s = this->toUlong();
	return  s >= 0x80000000 && s <= 0xBFFFFFFF;
}

bool ip::Address::isClassC() const
{
	unsigned long s = this->toUlong();
	return s >= 0xC0000000 && s <=  0xDFFFFFFF;
}

std::string	ip::Address::toString() const
{
	char str[INET_ADDRSTRLEN];
	const char *p =	::inet_ntop(AF_INET,  PVOID(&this->_addr), str, INET_ADDRSTRLEN);
	if (p == 0)
		return std::string();
	return str;
}

unsigned long	ip::Address::toUlong() const
{
	return this->_addr.s_addr;
}

ip::Address ip::Address::any()
{
	return Address(INADDR_ANY);
}

ip::Address ip::Address::broadcast()
{
	return Address(INADDR_BROADCAST);
}

ip::Address ip::Address::broadcast(const Address & addr, const Address & mask)
{
	return Address(INADDR_BROADCAST);
}
ip::Address ip::Address::fromString(const std::string & str)
{
	return Address(inet_addr(str.c_str()));
}

ip::Address ip::Address::loopBack()
{
	return Address(INADDR_LOOPBACK);
}

ip::Address ip::Address::netmask(const Address& addr)
{
	if (addr.isClassA())
		return Address(0xFF000000);
	if (addr.isClassB())
		return Address(0xFFFF0000);
	if (addr.isClassC())
		return Address(0xFFFFFF00);
	return Address(0xFFFFFFFF);
}

bool ip::Address::operator==(const Address& addr)
{
	return this->toUlong() == addr.toUlong();
}

bool ip::Address::operator!=(const Address& addr)
{
	return !(*this == addr);
}

bool ip::Address::operator<(const Address& addr)
{
	return this->toUlong() < addr.toUlong();
}

bool ip::Address::operator>(const Address& addr)
{
	return !(*this < addr);
}

IN_ADDR ip::Address::data() const
{
	return this->_addr;
}