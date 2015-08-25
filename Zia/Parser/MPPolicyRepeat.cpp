#include <sstream>

#include "MPPolicyRepeat.h"
#include "MPParser.hpp"
#include "api/DataTree.hpp"
#include "IMPRule.h"

bool	MPPolicyRepeat::parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule)
{
	MPParser::ParsingMode	curMode = theParser->mode();
	const std::string&	tempMsg = theParser->getMessage().getCurMsg();
	bool	result = true;

	theParser->switchMode(MPParser::CONSUME);
	int nbBoucle;
	for (nbBoucle = 0; result == true; nbBoucle++)
	{
		theParser->separator();
		result = theRule.rule(theParser, theTree);
		if (result == true)
			theParser->consume(theRule);
	}
	if (curMode == MPParser::CHECK || (result == false && nbBoucle == 0))
		theParser->getMessage().updateMessage(tempMsg);
	theParser->switchMode(curMode);
	delete &theRule;
	if (nbBoucle >= 1)
		return true;
	return false;
}
