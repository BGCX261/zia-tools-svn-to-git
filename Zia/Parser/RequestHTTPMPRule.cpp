#include "RequestHTTPMPRule.h"
#include "MPParser.hpp"

#include "RequestLineMPRule.h"
#include "HeaderHTTPMPRule.h"
#include "MPPolicyMust.h"
#include "CompareMPRule.h"

bool	RequestHTTPMPRule::rule(MPParser* theParser, zia::api::DataTree &theTree)
{
	if (theParser->loadRule<RequestLineMPRule, MPPolicyMust>(theTree["Request-Line"]) == true &&
		theParser->loadRule<HeaderHTTPMPRule, MPPolicyMust>(theTree["Header"]) == true &&
		theParser->loadRule<CompareMPRule, MPPolicyMust>("\r\n") == true)
	{
		return true;
	}
	return false;
}