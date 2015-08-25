#include <string>



#include "MPParser.hpp"
#include "RequestLineMPRule.h"

#include "ReadUntilMPRule.h"
#include "StringMPRule.h"
#include "MPPolicyMust.h"
#include "AbsolutPathMPRule.h"


bool	RequestLineMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	if (theParser->loadRule<StringMPRule, MPPolicyMust>(theTree["Method"]) == true &&
		theParser->loadRule<AbsolutPathMPRule, MPPolicyMust>(theTree["Request-URI"]) == true &&
		theParser->loadRule<ReadUntilMPRule, MPPolicyMust>("\r\n", theTree["HTTP-Version"]) == true)
	{
		return true;
	}
	return false;
}
