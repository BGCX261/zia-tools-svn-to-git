#include "ReadUntilMPRule.h"
#include "MPParser.hpp"

ReadUntilMPRule::ReadUntilMPRule(const std::string& compValue)
: _compValue(compValue)
{}

bool	ReadUntilMPRule::rule(MPParser* theParser, zia::api::DataTree &theTree)
{
	this->_nbrMatch = theParser->getMessage().getCurMsg().find(this->_compValue);
	if (this->_nbrMatch == -1 && this->_compValue.size() > 0)
		return false;
	if (!this->_compValue.size())
		this->_nbrMatch = theParser->getMessage().getCurMsg().size();
	theTree = theParser->getMessage().getCurMsg().substr(0, this->_nbrMatch);
	this->_nbrMatch += this->_compValue.size();
	return true;
}