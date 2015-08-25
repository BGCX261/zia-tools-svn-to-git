#pragma once

#include <iostream>
#include <algorithm>
#include "ModuleFinder.h"
#include "TaskPool.h"

namespace ip{
	namespace tcp{
		class AcceptorTcp;
	};
};
namespace zia
{
	class Zia
	{
	
	private:
		zia::core::ModuleFinder	_finder;
		void					loopConnection(int i = 0);
		std::list<ip::tcp::AcceptorTcp*>	_acceptors;
		thread::TaskPool					_pool;
	
	public:
		Zia(void);
		~Zia(void);
		void	start();
	};
};