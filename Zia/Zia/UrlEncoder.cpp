#include <algorithm>
#include <sstream>
#include "UrlEncoder.h"

const std::string zia::utils::UrlEncoder::authorizedChar = "/-_.!~*'()";

zia::utils::UrlEncoder::UrlEncoder(void)
{
}


zia::utils::UrlEncoder::~UrlEncoder(void)
{

}

zia::utils::UrlEncoder::UrlEncoder(const UrlEncoder& other)
	: _encode(other._encode)
{

}

zia::utils::UrlEncoder&	zia::utils::UrlEncoder::operator=(const UrlEncoder& other)
{
	this->_encode = other._encode;
	return *this;
}

void	zia::utils::UrlEncoder::operator()(const char c)
{
	if ((c >= '0' && c <= '9') || 
		(c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z') ||
		authorizedChar.find(c) != std::string::npos
		)
	{
		this->_encode +=  c;
		return;
	}
	std::ostringstream oss;
	oss << std::hex << (int)c;
	this->_encode +=  '%' + oss.str();
}

const std::string& zia::utils::UrlEncoder::urlEncode() const
{
	return this->_encode;
}

std::string	zia::utils::UrlEncoder::urlEncode(const std::string& url)
{
	UrlEncoder	urlencode;
	urlencode = std::for_each(url.begin(), url.end(), urlencode);
	return urlencode.urlEncode();
}

  