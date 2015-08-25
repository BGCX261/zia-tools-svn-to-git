#ifndef __KEYVALUEMPRULE_H__
# define __KEYVALUEMPRULE_H__

#include "IMPRule.h"
#include "api/DataTree.hpp"



class	KeyValueMPRule : public IMPRule
{
public:
	KeyValueMPRule(const std::string& separator = "=", const std::string& end = "\r\n");
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree());
private:
	std::string	_separator;
	std::string	_end;
};

#endif /* __KEYVALUEMPRULE_H__ */