#ifndef __REQUESTLINEMPRULE_H__
# define __REQUESTLINEMPRULE_H__

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	RequestLineMPRule : public IMPRule
{
public:
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
};

#endif /* __REQUESTLINEMPRULE_H__ */