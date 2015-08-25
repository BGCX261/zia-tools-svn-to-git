#ifndef __CONFCONTENTMPRULE_H__
# define __CONFCONTENTMPRULE_H__

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	ConfContentMPRule : public IMPRule
{
public:
	ConfContentMPRule();
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
};

#endif /* __CONFCONTENTMPRULE_H__ */