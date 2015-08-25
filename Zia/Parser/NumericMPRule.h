#ifndef __NUMERICMPRULE_H__
#define __NUMERICMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"


class	NumericMPRule : public IMPRule
{
public:
	NumericMPRule();
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	const std::string	_compValue;
};

#endif /* __NUMERICMPRULE_H__ */