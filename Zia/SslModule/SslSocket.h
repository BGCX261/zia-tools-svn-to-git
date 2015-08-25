#pragma once

#include <openssl/ssl.h>
#include <openssl/err.h>
#include "SslContext.h"

class SslSocket
{
private:
	SSL*	_ssl;
	long	_mode;

public:
	SslSocket(const SslContext& ctx, long mode = SSL_MODE_AUTO_RETRY);
	SslSocket();
	~SslSocket(void);
	void	setMode(long mode);
	void	setContext(const SslContext& ctx);
	void	setSocket(int fd);
	void	accept();
	void	connect();
	int		pending() const;
	int		shutdown();
	void	setShutDown(int mode);
	int		getShutDown() const;
	int		clear();
	template<typename T>
	int	write(const T* data, int len) const;
	template<typename T>
	int read(T*, int);
};

template<typename T>
int	SslSocket::write(const T* data, int len) const
{
	int w = SSL_write(this->_ssl, data, len);
	return w;
}

template<typename T>
int	SslSocket::read(T* data, int len)
{
	int r = SSL_write(this->_ssl, data, len);
	return r;
}