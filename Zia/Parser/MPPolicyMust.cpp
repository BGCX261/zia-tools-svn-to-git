

#include "MPPolicyMust.h"
#include "MPParser.hpp"
#include "api/DataTree.hpp"
#include "IMPRule.h"

bool	MPPolicyMust::parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule)
{
	MPParser::ParsingMode	curMode = theParser->mode();
	const std::string&	tempMsg = theParser->getMessage().getCurMsg();

	theParser->switchMode(MPParser::CONSUME);
	theParser->separator();
	bool	result = theRule.rule(theParser, theTree);
	if (curMode == MPParser::CHECK || result == false)
		theParser->getMessage().updateMessage(tempMsg);
	else if (curMode == MPParser::CONSUME && result == true)
		theParser->consume(theRule);
	theParser->switchMode(curMode);
	delete &theRule;
	return result;
}