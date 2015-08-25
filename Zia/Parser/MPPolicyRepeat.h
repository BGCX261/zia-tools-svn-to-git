#ifndef __MPPOLICYREPEAT_H__
#define __MPPOLICYREPEAT_H__

#include "api/DataTree.hpp"
#include "IMPRule.h"



class	MPParser;

class	MPPolicyRepeat
{
public:
	bool	parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule);
};

#endif /* __MPPOLICYREPEAT_H__ */