#ifndef __HEXADECIMALMPRULE_H__
#define __HEXADECIMALMPRULE_H__

#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	HexadecimalMPRule : public IMPRule
{
public:
	HexadecimalMPRule();
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	const std::string	_compValue;
};

#endif /* __HEXADECIMALMPRULE_H__ */