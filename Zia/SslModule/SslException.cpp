#include "SslException.h"

SslException::SslException(SslException::exception_type id, const std::string& msg)
: std::exception(), _msg(msg), _id(id)
{

}

SslException::~SslException(void)
{
}

const char* SslException::what() const throw()
{
	return _msg.c_str();
}