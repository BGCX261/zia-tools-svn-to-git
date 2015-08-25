#include <string>



#include "MPParser.hpp"
#include "AlphaNumMPRule.h"
#include "NumericMPRule.h"
#include "StringMPRule.h"
#include "MPPolicyMust.h"

AlphaNumMPRule::AlphaNumMPRule()
: _compValue("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789")
{}

bool	AlphaNumMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	this->_nbrMatch = theParser->getMessage().getCurMsg().find_first_not_of(this->_compValue);
	if (this->_nbrMatch == std::string::npos)
		this->_nbrMatch = theParser->getMessage().getCurMsg().size();
	if (this->_nbrMatch <= 0)
		return false;
	theTree = theParser->getMessage().getCurMsg().substr(0, this->_nbrMatch);
	return true;
}