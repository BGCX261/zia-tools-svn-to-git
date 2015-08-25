#pragma once

#include "ConnectionBase.h"
#include "ZiaMessage.h"
#include "ModuleFinder.h"
#include "AllocateModule.h"
#include "Linker.h"
#include "api/AStream.hpp"

namespace ip{
	namespace tcp{
		class AcceptorTcp;
	}

}

namespace zia{

	class ConnectionBase;
	namespace core{

	
		class NewConnection
		{
		private:
			zia::ZiaMessage*							_ziaMessage;
			zia::core::AllocateModule					_allocator;
			zia::core::Linker							_linker;
			

			zia::ConnectionBase							_connectionBase;
			ip::tcp::socket								_client;
			std::list<zia::api::HandlerModuleUnload>	_listUnload;
			std::list<zia::api::HandlerModule>			_listLoad;
			
			void										startRead();
			int											startWrite(zia::api::AStream& inStream);

		public:

			NewConnection();
			~NewConnection(void);
			NewConnection(const NewConnection& other);
			NewConnection& operator=(const NewConnection& other);
			void	operator()(const ip::tcp::socket& socket);
			void	handlerUnLoad(const std::list<zia::api::HandlerModuleUnload>&);
			void	handlerLoad(const std::list<zia::api::HandlerModule>&);
		};
	};
};
