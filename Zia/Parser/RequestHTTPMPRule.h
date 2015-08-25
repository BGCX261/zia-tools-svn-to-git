#ifndef __REQUESTHTTPMPRULE_H__
# define __REQUESTHTTPMPRULE_H__

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	RequestHTTPMPRule : public IMPRule
{
public:
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
};

#endif /* __REQUESTHTTPMPRULE_H__ */