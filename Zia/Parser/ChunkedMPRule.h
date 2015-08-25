#ifndef __CHUNKEDMPRULE_H__
# define __CHUNKEDMPRULE_H__

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	ChunkedMPRule : public IMPRule
{
public:
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
};

#endif /* __CHUNKEDMPRULE_H__ */