#pragma once

#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


class CountObject
{

private:
	static	unsigned int	_compt;

public:
	CountObject();
	 virtual ~CountObject() = 0;
};
