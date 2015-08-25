
#include "ChunkedMPRule.h"
#include "MPParser.hpp"

#include "HexadecimalMPRule.h"
#include "ReadUntilMPRule.h"
#include "MPPolicyMust.h"

bool	ChunkedMPRule::rule(MPParser* theParser, zia::api::DataTree &theTree)
{
	if (theParser->loadRule<HexadecimalMPRule, MPPolicyMust>(theTree["Size"]) && theParser->loadRule<ReadUntilMPRule, MPPolicyMust>("/r/n", theTree["Value"]))
	{
		return true;
	}
	return false;
}