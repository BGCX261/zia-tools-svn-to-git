
#include <string>

#include "MPParser.hpp"
#include "HeaderHTTPMPRule.h"

#include "KeyValueMPRule.h"
#include "MPPolicyRepeat.h"

bool	HeaderHTTPMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	if (theParser->loadRule<KeyValueMPRule, MPPolicyRepeat>(":", theTree) == true)
	{
		return true;
	}
	return false;
}
