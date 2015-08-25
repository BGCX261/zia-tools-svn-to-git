#ifndef __HEADERHTTPMPRULE_H__
# define __HEADERHTTPMPRULE_H__

#include "IMPRule.h"
#include "api/DataTree.hpp"

class	HeaderHTTPMPRule : public IMPRule
{
public:
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
};

#endif /* __HEADERHTTPMPRULE_H__ */