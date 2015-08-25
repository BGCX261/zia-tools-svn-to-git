#include "AbsolutPathMPRule.h"

#include "MPParser.hpp"
#include "ReadUntilMPRule.h"
#include "MPPolicyMust.h"
#include "ReadLastMPRule.h"

#include "api/DataTree.hpp"

AbsolutPathMPRule::AbsolutPathMPRule()
{}

bool	AbsolutPathMPRule::rule(MPParser* parser, zia::api::DataTree& theTree)
{
	if (parser->loadRule<ReadUntilMPRule, MPPolicyMust>(" ", theTree) )
	{
		MPParser	oParser(theTree.v());
		theTree["Full"] = theTree.v();
		oParser.loadRule<ReadUntilMPRule, MPPolicyMust>("?", theTree);
		oParser.changeMessage(theTree.v());
		oParser.loadRule<ReadLastMPRule, MPPolicyMust>(".", theTree["Extention"]);
		return true;
	}
	return false;
}