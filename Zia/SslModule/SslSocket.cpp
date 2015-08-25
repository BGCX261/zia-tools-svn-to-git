#include "SslSocket.h"
#include "SslException.h"

SslSocket::SslSocket(const SslContext& ctx, long mode)
: _ssl(0), _mode(mode)
{
	setContext(ctx);
}

SslSocket::SslSocket()
: _ssl(0), _mode(SSL_MODE_AUTO_RETRY)
{

}

SslSocket::~SslSocket(void)
{
	SSL_free(this->_ssl);
}

void	SslSocket::setMode(long mode)
{
	this->_mode = mode;
	SSL_set_mode(this->_ssl, this->_mode);
}

void	SslSocket::setContext(const SslContext& ctx)
{
	this->_ssl = SSL_new(ctx.getContext());
}

void	SslSocket::setSocket(int fd)
{
	if (SSL_set_fd(this->_ssl, fd) != 1)
		throw SslException(SslException::SSL_SOCKET, ERR_error_string(ERR_get_error(), NULL));
}

void	SslSocket::accept()
{
	int res = SSL_accept(this->_ssl);
	if (res != 1)
		throw SslException(SslException::SSL_SOCKET, ERR_error_string(ERR_get_error(), NULL));
}

void	SslSocket::connect()
{
	int res = SSL_connect(this->_ssl);
	if (res != 1)
		throw SslException(SslException::SSL_SOCKET, ERR_error_string(ERR_get_error(), NULL));
}

int	SslSocket::pending() const
{
	return SSL_pending(this->_ssl);
}

int	SslSocket::shutdown()
{
	return SSL_shutdown(this->_ssl);
}

void	SslSocket::setShutDown(int mode)
{
	SSL_set_shutdown(this->_ssl, mode);
}

int		SslSocket::getShutDown() const
{	
	return SSL_get_shutdown(this->_ssl);
}

int	SslSocket::clear()
{
	return SSL_clear(this->_ssl);
}