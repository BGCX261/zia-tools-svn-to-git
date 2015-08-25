#ifndef __MPPOLICYMUST_H__
#define __MPPOLICYMUST_H__

#include "api/DataTree.hpp"
#include "IMPRule.h"


class	MPParser;

class	MPPolicyMust
{
public:
	bool	parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule);
};

#endif /* __MPPOLICYMUST_H__ */