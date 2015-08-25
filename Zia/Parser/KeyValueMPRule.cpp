
#include <string>

#include "MPParser.hpp"
#include "KeyValueMPRule.h"

#include "ReadUntilMPRule.h"
#include "MPPolicyMust.h"

KeyValueMPRule::KeyValueMPRule(const std::string& separator, const std::string& end)
	: _separator(separator), _end(end)
{}

bool	KeyValueMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	zia::api::DataTree	data;
	if (theParser->loadRule<ReadUntilMPRule, MPPolicyMust>(this->_separator, data) == true && theParser->loadRule<ReadUntilMPRule, MPPolicyMust>(this->_end, data["value"]) == true)
	{
		theTree[data.v()] = data["value"].v();
		return true;
	}
	return false;
}