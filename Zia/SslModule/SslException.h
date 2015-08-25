#pragma once

#include <exception>
#include <string>

class SslException
	: public std::exception
{

public:
	enum exception_type
	{
		CONTEXT = 0,
		SSL_SOCKET
	};

	SslException(SslException::exception_type id, const std::string&);
	~SslException(void); 
	virtual const char* what() const throw();

private:
	std::string		_msg;
	SslException::exception_type	_id;
};
