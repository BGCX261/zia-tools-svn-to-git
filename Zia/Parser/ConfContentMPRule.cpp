
#include <string>
#include <map>
#include "MPParser.hpp"
#include "ConfContentMPRule.h"

#include "ReadUntilMPRule.h"
#include "StringMPRule.h"
#include "MPPolicyMust.h"
#include "MPPolicyRepeatTab.h"

ConfContentMPRule::ConfContentMPRule()
{}

bool	ConfContentMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	zia::api::DataTree	data;
	if (theParser->loadRule<ReadUntilMPRule, MPPolicyMust>(":", data) == true && theParser->loadRule<StringMPRule, MPPolicyRepeatTab>(data) == true)
	{
		std::map<std::string, zia::api::DataTree>::const_iterator	it = data.mSubs.begin();
		for (; it != data.mSubs.end(); it++)
		{
			theTree[(*it).second.v()] = data.v();
		}
		return true;
	}
	return false;
}