#ifndef __STRINGMPRULE_H__
#define __STRINGMPRULE_H__

#include <string>



#include "IMPRule.h"
#include "api/DataTree.hpp"

class	StringMPRule : public IMPRule
{
public:
	StringMPRule();
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	const std::string	_compValue;
};

#endif /* __STRINGRULE_H__ */