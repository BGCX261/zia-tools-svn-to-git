#include <string>

#include "MPParser.hpp"
#include "MPOption.h"

MPOption::MPOption(const std::string& optValue)
	: _optValue(optValue)
{}

bool MPOption::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	this->_nbrMatch = theParser->getMessage().getCurMsg().find_first_not_of(this->_optValue);
	if (this->_nbrMatch > 0)
		return true;
	return false;
}

void	MPOption::setOption(const std::string& opt)
{
	this->_optValue = opt;
}

const MPOption&	MPOption::saveOption()
{
	return *this;
}

bool	MPOption::parse(MPParser* theParser)
{
	bool	result = this->rule(theParser, zia::api::DataTree());
	theParser->consume(*this);
	return result;
}