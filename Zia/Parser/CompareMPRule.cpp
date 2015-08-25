#include "CompareMPRule.h"

#include "MPParser.hpp"

CompareMPRule::CompareMPRule(const std::string& compValue)
	: _compValue(compValue)
{}

bool	CompareMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	if (this->_compValue.compare(0, this->_compValue.size(), theParser->getMessage().getCurMsg()) == 0)
	{
		theTree = this->_compValue;
		return true;
	}
	return false;
}
