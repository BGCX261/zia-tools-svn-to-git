#ifndef __ALPHANUMMPRULE_H__
#define __ALPHANUMMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	AlphaNumMPRule : public IMPRule
{
public:
	AlphaNumMPRule();
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	const std::string	_compValue;
};

#endif /* __ALPHANUMMPRULE_H__ */