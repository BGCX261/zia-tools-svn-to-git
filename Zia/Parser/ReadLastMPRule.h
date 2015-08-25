#ifndef __READLASTMPRULE_H__
#define __READLASTMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"


class	ReadLastMPRule : public IMPRule
{
public:
	ReadLastMPRule(const std::string& compValue);
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	const std::string	_compValue;
};

#endif /* __READLASTMPRULE_H__ */