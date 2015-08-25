#ifndef __MPPOLICYOPTIONAL_H__
#define __MPPOLICYOPTIONAL_H__

#include "api/DataTree.hpp"
#include "IMPRule.h"

class	MPParser;

class	MPPolicyOptional
{
public:
	bool	parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule);
};

#endif /* __MPPOLICYOPTIONAL_H__ */