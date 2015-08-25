#include <iostream>
#include <openssl/err.h>
#include "SslContext.h"
#include "SslException.h"

SslContext::SslContext(void)
: SslInit(), _ctx(0)
{
	this->_ctx = SSL_CTX_new(SSLv23_method());
}

SslContext::~SslContext(void)
{
	SSL_CTX_free(_ctx);
}

void	SslContext::setCerti(const std::string &file, TYPE_FILE)
{
	this->_certi = file;
	if (!SSL_CTX_use_certificate_file(this->_ctx, this->_certi.c_str(),SSL_FILETYPE_PEM))
		throw SslException(SslException::CONTEXT , ERR_error_string(ERR_get_error(), NULL));
}

void	SslContext::setPrivateKey(const std::string& file, TYPE_FILE)
{
	this->_key = file;
	if (!SSL_CTX_use_PrivateKey_file(this->_ctx, this->_key.c_str(), SSL_FILETYPE_PEM))
		throw SslException(SslException::CONTEXT , ERR_error_string(ERR_get_error(), NULL));

}

void	SslContext::setContext(const std::string& certi, const std::string& key, TYPE_FILE type)
{
	this->setCerti(certi, type);
	this->setPrivateKey(key, type);
	if(!SSL_CTX_check_private_key(this->_ctx))
		throw SslException(SslException::CONTEXT , ERR_error_string(ERR_get_error(), NULL));
}

SSL_CTX* const SslContext::getContext() const
{
	return this->_ctx;
}