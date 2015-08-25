#include <sstream>

#include "MPPolicyOptionalRepeat.h"
#include "MPParser.hpp"
#include "api/DataTree.hpp"
#include "IMPRule.h"

bool	MPPolicyOptionalRepeat::parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule)
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
		flux << nbBoucle;
		nbBoucleString = flux.str();
		theParser->separator();
		result = theRule.rule(theParser, theTree[nbBoucleString]);
		if (result == true)
			theParser->consume(theRule);
		flux.str("");
	}
	if (curMode == MPParser::CHECK)
		theParser->getMessage().updateMessage(tempMsg);
	theParser->switchMode(curMode);
	delete &theRule;
	return true;
}