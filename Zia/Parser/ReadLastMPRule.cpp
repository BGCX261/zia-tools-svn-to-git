#include "ReadLastMPRule.h"

#include "MPParser.hpp"

ReadLastMPRule::ReadLastMPRule(const std::string& compValue)
	: _compValue(compValue)
{}

bool	ReadLastMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	this->_nbrMatch = theParser->getMessage().getCurMsg().rfind(this->_compValue);
	if (this->_nbrMatch == -1)
		return false;
	theTree = theParser->getMessage().getCurMsg().substr(this->_nbrMatch + this->_compValue.size());
	this->_nbrMatch += this->_compValue.size();
	return true;
}