#pragma once

#ifndef WINSOCK2_NODEFINE
#define WINSOCK2_NODEFINE

#include <Ws2tcpip.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#endif


namespace ip{
	namespace detail{
typedef SOCKET socket_type;
const SOCKET invalid_socket = INVALID_SOCKET;
const int socket_error_retval = SOCKET_ERROR;
const int max_addr_v4_str_len = 256;
const int max_addr_v6_str_len = 256;
typedef sockaddr socket_addr_type;
typedef in_addr in4_addr_type;
typedef ip_mreq in4_mreq_type;
typedef sockaddr_in sockaddr_in4_type;
typedef sockaddr_storage sockaddr_storage_type;
typedef sockaddr_in6 sockaddr_in6_type;
	};
};