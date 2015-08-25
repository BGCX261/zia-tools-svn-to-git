#pragma once

#include "BasicEndpoint.hpp"
#include "Tcp.h"
namespace ip{
	
	namespace tcp{

		typedef ip::BasicEndpoint<Tcp> endpoint;

	};

	namespace udp{

		//typedef BasicEnpoint<Udp> endpoint;

	};
};