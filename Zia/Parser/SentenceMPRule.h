#ifndef __SENTENCEMPRULE_H__
#define __SENTENCEMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	SentenceMPRule : public IMPRule
{
public:
	SentenceMPRule();
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	const std::string	_compValue;
};

#endif /* __SENTENCEMPRULE_H__ */