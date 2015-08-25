#ifndef __IMPRULE_H__
#define __IMPRULE_H__



#include "api/DataTree.hpp"

class	MPParser;

class	IMPRule
{
public:
	IMPRule();
	virtual bool	rule(MPParser* theParser, zia::api::DataTree& theTree = zia::api::DataTree()) = 0;
	size_t	getNbrMatch() const;
protected:
	size_t	_nbrMatch;
};

#endif /* __IMPRULE_H__ */