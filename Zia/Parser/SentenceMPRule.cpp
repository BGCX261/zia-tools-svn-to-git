#include <string>

#include "MPParser.hpp"
#include "SentenceMPRule.h"
#include "AlphaNumMPRule.h"
#include "MPPolicyRepeat.h"


SentenceMPRule::SentenceMPRule()
{}

bool	SentenceMPRule::rule(MPParser* theParser, zia::api::DataTree& theTree)
{
	if (theParser->loadRule<AlphaNumMPRule, MPPolicyRepeat>(theTree["Sentence"]) == true)
		return true;
	return false;
}