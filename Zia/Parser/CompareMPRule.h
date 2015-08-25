#ifndef __COMPAREMPRULE_H__
#define __COMPAREMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"

class	CompareMPRule : public IMPRule
{
public:
	CompareMPRule(const std::string& compValue);
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	std::string	_compValue;
};

#endif /* __COMPAREMPRULE_H__ */