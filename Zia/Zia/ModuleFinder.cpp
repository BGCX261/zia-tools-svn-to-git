#include "ModuleFinder.h"
#include "api/IModule.hpp"
#include "AbsDl.h"
#include <iostream>



const std::string	zia::core::ModuleFinder::module_handler_name = "module_new";
const std::string	zia::core::ModuleFinder::module_handlerdel_name = "module_delete";
const std::string	zia::core::ModuleFinder::global_handler_name ="dll_load";
const std::string	zia::core::ModuleFinder::global_handlerdel_name = "dll_unload";

zia::core::ModuleFinder::ModuleFinder(void)
: _moduleHandleMap()
{

}


zia::core::ModuleFinder::~ModuleFinder(void)
{

}

void	zia::core::ModuleFinder::addModule(const std::string& modulename)
{
	void* handle = 0;
	handle = (AbsDl::getInstance()).open(modulename);	
	if (handle != 0)
		this->_moduleHandleMap[modulename] = handle;
}

void	zia::core::ModuleFinder::deleteModule(const std::string& modulename)
{
	std::map<std::string, void*>::iterator it = this->_moduleHandleMap.find(modulename);
	if (it != this->_moduleHandleMap.end())
		AbsDl::getInstance().close(it->second);
}	

std::list<zia::api::HandlerModule>	zia::core::ModuleFinder::allHandlerModule()
{
	std::map<std::string, void*>::iterator	it = this->_moduleHandleMap.begin();
	std::list<zia::api::HandlerModule>		listHandlerModule;
	for(; it != this->_moduleHandleMap.end(); it++)
	{
		try{
			zia::api::HandlerModule	ptr = static_cast<zia::api::HandlerModule>(AbsDl::getInstance().load(it->second, module_handler_name));
			listHandlerModule.push_back(ptr);
		}
		catch (const msg_error& e)
		{
			//std::cerr << "Warning: from " << it->first << " " <<  e.what() << " "<< std::endl;
		}
	}
	return listHandlerModule;
}

std::list<zia::api::HandlerModuleUnload>	zia::core::ModuleFinder::allHandlerModuleUnload()
{
	std::map<std::string, void*>::iterator	it = this->_moduleHandleMap.begin();
	std::list<zia::api::HandlerModuleUnload>		listHandler;
	for(; it != this->_moduleHandleMap.end(); it++)
	{
		try
		{
			zia::api::HandlerModuleUnload	ptr = static_cast<zia::api::HandlerModuleUnload>(AbsDl::getInstance().load(it->second, module_handlerdel_name));
			listHandler.push_back(ptr);
		}
		catch (const msg_error& e)
		{
			//std::cerr << "Warning: from " << it->first <<  " "  << e.what() << " " << std::endl;
		}
	}
	return listHandler;
}

std::list<zia::api::HandlerLoad>	zia::core::ModuleFinder::allHandlerLoad()
{
	std::map<std::string, void*>::iterator	it = this->_moduleHandleMap.begin();
	std::list<zia::api::HandlerLoad>		listHandler;
	for(; it != this->_moduleHandleMap.end(); it++)
	{
		try{

			zia::api::HandlerLoad	ptr = static_cast<zia::api::HandlerLoad>(AbsDl::getInstance().load(it->second, global_handler_name));
			listHandler.push_back(ptr);
		}
		catch (const msg_error& e)
		{
			//std::cerr << "Warning: from "<< it->first << " " << e.what() << " " << std::endl;
		}
	}
	return listHandler;
}

std::list<zia::api::HandlerUnload>	zia::core::ModuleFinder::allHandlerUnload()
{
	std::map<std::string, void*>::iterator	it = this->_moduleHandleMap.begin();
	std::list<zia::api::HandlerUnload>		listHandler;
	for(; it != this->_moduleHandleMap.end(); it++)
	{
		try
		{
			zia::api::HandlerUnload	ptr = static_cast<zia::api::HandlerUnload>(AbsDl::getInstance().load(it->second, global_handlerdel_name));
			listHandler.push_back(ptr);
		}
		catch (const msg_error& e)
		{
		//	std::cerr << "Warning: from " << it->first << " " << e.what() << " " << std::endl;
		}
	}
	return listHandler;
}


zia::api::HandlerModule			zia::core::ModuleFinder::handlerModule(const std::string& modulename)
{
	try
	{
		void* handle = this->_moduleHandleMap.find(modulename)->second;
		zia::api::HandlerModule	ptr = static_cast<zia::api::HandlerModule>(AbsDl::getInstance().load(handle, module_handlerdel_name));
		return ptr;
	}
	catch (const msg_error& e)
	{
		//std::cerr << "Warning: from " << modulename << " " << e.what() << " " << std::endl;
	}
	return 0;
}
zia::api::HandlerModuleUnload	zia::core::ModuleFinder::handlerModuleUnload(const std::string& modulename)
{
	try
	{
		void* handle = this->_moduleHandleMap.find(modulename)->second;
		zia::api::HandlerModuleUnload	ptr = static_cast<zia::api::HandlerModuleUnload>(AbsDl::getInstance().load(handle, module_handlerdel_name));
		return ptr;
	}
	catch (const msg_error& e)
	{
		std::cerr << "Warning: from " << modulename << " " << e.what() << " " << std::endl;
	}
	return 0;
}
zia::api::HandlerLoad			zia::core::ModuleFinder::handlerLoad(const std::string& modulename)
{
	try
	{
		void* handle = this->_moduleHandleMap.find(modulename)->second;
		zia::api::HandlerLoad	ptr = static_cast<zia::api::HandlerLoad>(AbsDl::getInstance().load(handle, global_handler_name));
		return ptr;
	}
	catch (const msg_error& e)
	{
		//std::cerr << "Warning: from " << modulename << " " << e.what() << " " << std::endl;
	}
	return 0;
}

zia::api::HandlerUnload			zia::core::ModuleFinder::handlerUnload(const std::string& modulename)
{
	try
	{
		void* handle = this->_moduleHandleMap.find(modulename)->second;
		zia::api::HandlerUnload	ptr = static_cast<zia::api::HandlerUnload>(AbsDl::getInstance().load(handle, global_handlerdel_name));
		return ptr;
	}
	catch (const msg_error& e)
	{
		//std::cerr << "Warning: from " << modulename << " " << e.what() << " " << std::endl;
	}
	return 0;
}