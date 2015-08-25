#ifndef __READUNTILMPRULE_H__
#define __READUNTILMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	ReadUntilMPRule : public IMPRule
{
public:
	ReadUntilMPRule(const std::string& compValue);
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	const std::string	_compValue;
};

#endif /* __READUNTILMPRULE_H__ */