#include "IConnection.hpp"

zia::api::IConnection::IConnection()
{

}

zia::api::IConnection::~IConnection()
{



}

zia::api::DataTree&  zia::api::IConnection::info()
{
	return *this->mInfos;
}

zia::api::ILog&                  zia::api::IConnection::log()
{
	return *this->mLog;
}

zia::api::IConnection&                zia::api::IConnection::operator=(const zia::api::IConnection& other)
{
	this->mLog = other.mLog;
	this->mInfos = other.mInfos;
	return *this;
}
