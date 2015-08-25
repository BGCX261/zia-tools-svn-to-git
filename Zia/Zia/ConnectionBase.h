#pragma once

#include "SocketTCP.h"
#include "api/IConnection.hpp"


namespace zia
{


		class ConnectionBase
			: public zia::api::IConnection
		{

		private:
			zia::api::FdCallback _readerCallback;
			zia::api::FdCallback _writerCallback;
			ip::tcp::socket*	 _socket;

		public:
			ConnectionBase(void);
			~ConnectionBase(void);
			ConnectionBase(const ConnectionBase& other);
			ConnectionBase& operator=(const ConnectionBase& connection);
			virtual void                 setFdReadCallback(zia::api::FdCallback callback = zia::api::FdCallback());
			virtual void                 setFdWriteCallback(zia::api::FdCallback callback = zia::api::FdCallback());
			virtual void				 close();
			void						 callSocketReader(zia::api::AStream* stream);
			void						 callSocketWriter(zia::api::AStream* stream);
			void						 socket(ip::tcp::socket& _socket);
			const ip::tcp::socket&		 socket() const;
		};
};