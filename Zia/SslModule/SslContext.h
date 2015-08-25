#pragma once
#include <openssl/ssl.h>
#include <string>
#include "SslInit.h"

class SslContext
	: public SslInit
{
private:
	SSL_CTX*	_ctx;
	std::string _key;
	std::string _certi;

public:

	enum TYPE_FILE
	{
		PEM = SSL_FILETYPE_PEM,
		ASN1 = SSL_FILETYPE_ASN1
	};
	SslContext(void);
	~SslContext(void);
	void		setCerti(const std::string& file, TYPE_FILE);
	void		setPrivateKey(const std::string& file, TYPE_FILE);
	void		setContext(const std::string& certi, const std::string& key, TYPE_FILE type = PEM);
	SSL_CTX* const	getContext() const;
};
