#include "SslContext.h"
#include "SslSocket.h"
#include <iostream>
#include <fstream>

int	main()
{
	SslContext	context;
	context.setContext("../Debug/cert.pem", "../Debug/key.pem", SslContext::PEM);
	SslSocket s(context);
	return true;
}