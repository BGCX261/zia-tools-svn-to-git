#include "api/IConnection.hpp"

zia::api::IConnection::IConnection()
{

}

zia::api::IConnection::~IConnection()
{



}

zia::api::DataRep&  zia::api::IConnection::info()
{
	return *this->mInfos;
}

zia::api::ILog&                  zia::api::IConnection::log()
{
	return *this->mLog;
}

