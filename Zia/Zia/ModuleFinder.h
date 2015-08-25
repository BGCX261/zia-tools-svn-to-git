#pragma once

#include <map>
#include <list>
#include "api/IModule.hpp"
#include "api/IConf.hpp"
#include "api/HttpStep.hpp"


namespace zia
{
	namespace api
	{
		typedef zia::api::IModule* (*HandlerModule)(std::list<zia::api::HttpStep::Pair>& stepsCallbacks,		
			zia::api::IConnection& connection,
			zia::api::IConf& conf);
		typedef void (*HandlerModuleUnload)(zia::api::IModule* moduleToDelete, zia::api::IConnection& connection);
		typedef void (*HandlerLoad)(zia::api::IConf& conf, zia::api::ILog& log);
		typedef void (*HandlerUnload)(zia::api::ILog& log);
	};

	class zia::api::IModule;

	namespace core{
		class ModuleFinder
		{
		private:
			std::map<std::string, void*>	_moduleHandleMap;
		public:
			ModuleFinder(void);
			~ModuleFinder(void);

			void	addModule(const std::string& modulename);
			void	deleteModule(const std::string& modulename);


			zia::api::HandlerModule			handlerModule(const std::string& modulename);
			zia::api::HandlerModuleUnload	handlerModuleUnload(const std::string& modulename);
			zia::api::HandlerLoad			handlerLoad(const std::string& modulename);
			zia::api::HandlerUnload			handlerUnload(const std::string& modulename);

			std::list<zia::api::HandlerModule>	allHandlerModule();
			std::list<zia::api::HandlerModuleUnload> allHandlerModuleUnload();
			std::list<zia::api::HandlerLoad>	allHandlerLoad();
			std::list<zia::api::HandlerUnload>	allHandlerUnload();

			static const std::string			module_handler_name;
			static const std::string			module_handlerdel_name;
			static const std::string			global_handler_name;
			static const std::string			global_handlerdel_name;
		};
	};
};