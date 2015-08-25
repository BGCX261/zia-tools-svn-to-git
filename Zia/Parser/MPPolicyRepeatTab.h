#ifndef __MPPOLICYREPEATTAB_H__
#define __MPPOLICYREPEATTAB_H__

#include "api/DataTree.hpp"
#include "IMPRule.h"



class	MPParser;

class	MPPolicyRepeatTab
{
public:
	bool	parse(MPParser* theParser, zia::api::DataTree& theTree, IMPRule& theRule);
};

#endif /* __MPPOLICYREPEATTAB_H__ */