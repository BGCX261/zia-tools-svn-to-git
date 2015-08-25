#include <algorithm>
#include "AllocateModule.h"
#include "api/IConnection.hpp"
#include "HttpPairSort.h"
#include "ZiaConfig.h"

zia::core::AllocateModule::AllocateModule()
	: _connection(0), _stepCallback()
{

}

zia::core::AllocateModule::~AllocateModule(void)
{

}

void	zia::core::AllocateModule::operator()(zia::api::HandlerModule& module_to_load)
{
	zia::api::IModule* module = module_to_load(this->_stepCallback, *this->_connection, *zia::ZiaConfig::getInstance());
	if (module != 0)
		this->_listModule.push_back(module);
}

void	zia::core::AllocateModule::sort()
{
	zia::core::HttpPairSort	sorter;
	this->_stepCallback.sort(sorter);
}


const std::list<zia::api::HttpStep::Pair>& zia::core::AllocateModule::stepCallback() const
{
	return this->_stepCallback;
}

zia::core::AllocateModule::AllocateModule(const AllocateModule& other)
	:  _stepCallback(other._stepCallback), _listModule(other._listModule)
{
	this->_connection = other._connection;
}

zia::core::AllocateModule&	 zia::core::AllocateModule::operator=(const AllocateModule& other)
{
	this->_connection = other._connection;
	this->_listModule = other._listModule;
	this->_stepCallback = other._stepCallback;
	return *this;
}

zia::api::IConnection* zia::core::AllocateModule::connection()
{
	return this->_connection;
}

void					zia::core::AllocateModule::connection(zia::api::IConnection* connection)
{
	this->_connection = connection;
}