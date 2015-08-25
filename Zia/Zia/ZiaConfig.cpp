
#include <fstream>

#include "ZiaConfig.h"
#include "MPParser.hpp"
#include "ConfContentMPRule.h"
#include "KeyValueMPRule.h"
#include "MPPolicyMust.h"

zia::ZiaConfig*	zia::ZiaConfig::_instance = 0;

zia::ZiaConfig::ZiaConfig(void)
	: zia::api::IConf()
{

}

zia::ZiaConfig::~ZiaConfig(void)
{
}

void	zia::ZiaConfig::loadFromConfFile(const std::string& path)
{
	this->loadContentType(path);
	this->loadStatusCode(path);
}

bool	zia::ZiaConfig::loadContentType(const std::string& path)
{
	std::string	confile("ContentType");
	char	buffer[2049];
	std::ifstream	theFile;
	theFile.open(path + confile + ".conf");
	if (theFile.is_open())
	{
		MPParser	confParse("");
		while (!theFile.eof())
		{
			theFile.getline(buffer, 2048);
			confParse.changeMessage(buffer);
			confParse.loadRule<ConfContentMPRule, MPPolicyMust>(this->operator[](confile));
		}
		return true;
	}
	return false;
}

bool	zia::ZiaConfig::loadStatusCode(const std::string& path)
{
	std::string	confile("StatusCode");
	char	buffer[2049];
	std::ifstream	theFile;
	theFile.open(path + confile + ".conf");
	if (theFile.is_open())
	{
		MPParser	confParse("");
		while (!theFile.eof())
		{
			theFile.getline(buffer, 2048);
			confParse.changeMessage(buffer);
			confParse.loadRule<KeyValueMPRule, MPPolicyMust>("=", "", (*this)[confile]);
		}
		return true;
	}
	return false;
}


zia::ZiaConfig*	zia::ZiaConfig::getInstance()
{
	if (_instance == 0)
		_instance = new ZiaConfig();
	return _instance;
}