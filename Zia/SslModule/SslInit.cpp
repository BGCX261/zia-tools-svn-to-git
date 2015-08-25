#include "SslInit.h"
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <iostream>

bool	SslInit::isInit = false;

SslInit::SslInit(void)
{
	init();
}

SslInit::~SslInit(void)
{
}

void	SslInit::init()
{
	if (SslInit::isInit == true)
		return;
	SSL_library_init();
	SSL_load_error_strings();
	OpenSSL_add_all_algorithms();
	SslInit::isInit = true;
}
