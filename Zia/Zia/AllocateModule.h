#pragma once

#include "ModuleFinder.h"

namespace zia{

	namespace api{
		class IConnection;
	};

	namespace core{

		class AllocateModule
		{
		private:
			zia::api::IConnection*	_connection;
			std::list<zia::api::HttpStep::Pair> _stepCallback;
			std::list<zia::api::IModule*>		_listModule;

		public:
			AllocateModule();
			AllocateModule(const AllocateModule&);
			~AllocateModule(void);
			AllocateModule&	operator=(const AllocateModule&);
			void	operator()(zia::api::HandlerModule&);
			zia::api::IConnection* connection();
			void					connection(zia::api::IConnection*);
			const std::list<zia::api::HttpStep::Pair>& stepCallback() const;
			void					sort();
		};
	};
};
