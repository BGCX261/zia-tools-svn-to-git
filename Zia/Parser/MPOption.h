#ifndef __MPOPTION_H__
# define __MPOPTION_H__



#include <string>

#include "IMPRule.h"
#include "api/DataTree.hpp"

class	MPOption : public IMPRule
{
public:
	MPOption(const std::string& optValue = " \t");
	virtual bool	rule(MPParser* parser, zia::api::DataTree& theTree = zia::api::DataTree());
	void	setOption(const std::string& opt);
	const MPOption&	saveOption();
	bool	parse(MPParser* theParser);
private:
	std::string	_optValue;
};

#endif /* __MPOPTION_H__ */
