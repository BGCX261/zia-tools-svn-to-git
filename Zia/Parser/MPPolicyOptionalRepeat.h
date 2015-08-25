#ifndef __MPPOLICYOPTIONALREPEAT_H__
#define __MPPOLICYOPTIONALREPEAT_H__

#include "api/DataTree.hpp"
#include "IMPRule.h"



class	MPParser;

class	MPPolicyOptionalRepeat
{
public:
	bool	parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule);
};

#endif /* __MPPOLICYOPTIONALREPEAT_H__ */