#include <sstream>

#include "MPPolicyRepeatTab.h"
#include "MPParser.hpp"
#include "api/DataTree.hpp"
#include "IMPRule.h"

bool	MPPolicyRepeatTab::parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule)
{
	MPParser::ParsingMode	curMode = theParser->mode();
	const std::string&	tempMsg = theParser->getMessage().getCurMsg();
	bool	result = true;


    std::ostringstream	flux;
    std::string	nbBoucleString;
	theParser->switchMode(MPParser::CONSUME);
	int nbBoucle;
	for (nbBoucle = 0; result == true; nbBoucle++)
	{
		zia::api::DataTree	curTree;
		theParser->separator();
		result = theRule.rule(theParser, curTree);
		if (result == true)
		{
			flux << nbBoucle;
			nbBoucleString = flux.str();
			theTree[nbBoucleString] = curTree;
			theParser->consume(theRule);
			flux.str("");
		}
	}
	if (curMode == MPParser::CHECK || (result == false && nbBoucle == 0))
		theParser->getMessage().updateMessage(tempMsg);
	theParser->switchMode(curMode);
	delete &theRule;
	if (nbBoucle >= 1)
		return true;
	return false;
}
