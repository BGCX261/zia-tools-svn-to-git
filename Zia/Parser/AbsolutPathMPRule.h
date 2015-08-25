#ifndef __ABSOLUTPATHMPRULE_H__
#define __ABSOLUTPATHMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"

class	AbsolutPathMPRule : public IMPRule
{
public:
	AbsolutPathMPRule();
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
};

#endif /* __ABSOLUTPATHMPRULE_H__ */