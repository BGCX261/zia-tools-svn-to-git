#include "api/ILog.hpp"


zia::api::ILog::ILog()
{

}

zia::api::ILog::~ILog()
{

}

zia::api::ILog&               zia::api::ILog::operator<<(std::ostream& (*pf)(std::ostream&))
{
	if (pf == std::endl) 
		flush(); 
	return *this;
}