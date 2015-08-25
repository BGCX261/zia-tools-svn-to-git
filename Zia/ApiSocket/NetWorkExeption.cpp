#include "NetWorkExeption.h"
#include <sstream>
#include <iostream>

namespace ip
{
	NetWorkExeption::NetWorkExeption(int from, unsigned long lasterror, int errorlvl)
		: _lvl(errorlvl), _id(from)
	{
		_lasterror = lasterror;
	}


	NetWorkExeption::~NetWorkExeption(void) throw()
	{

	}

	const char* NetWorkExeption::what() const throw()
	{
		return "error";
	}

	int	NetWorkExeption::from() const
	{
		return this->_id;
	}
};