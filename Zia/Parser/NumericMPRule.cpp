#include <string>

#include "MPParser.hpp"
#include "NumericMPRule.h"


NumericMPRule::NumericMPRule()
: _compValue("0123456789")
{}

bool	NumericMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	this->_nbrMatch = theParser->getMessage().getCurMsg().find_first_not_of(this->_compValue);
	if (this->_nbrMatch == std::string::npos)
		this->_nbrMatch = theParser->getMessage().getCurMsg().size();
	if (this->_nbrMatch <= 0)
		return false;
	theTree = theParser->getMessage().getCurMsg().substr(0, this->_nbrMatch);
	return true;
}