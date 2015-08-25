#ifndef __MPPARSER_H__
#define __MPPARSER_H__

#include <string>
#include <iostream>



#include "api/DataTree.hpp"
#include "MPOption.h"
#include "MPMessage.h"
#include "MPPolicyOptional.h"

class	MPParser
{
public:

	enum	ParsingMode{
		CONSUME = 0,
		CHECK
		};

	MPParser(const MPMessage& message, MPParser::ParsingMode mode = MPParser::CHECK) : _message(message), _mode(mode)
	{}
	MPParser(const std::string& message, MPParser::ParsingMode mode = MPParser::CHECK) : _message(message), _mode(mode)
	{}

	template <class R, class P>
	bool	loadRule(zia::api::DataTree& theTree = zia::api::DataTree())
	{
		IMPRule*	theRule = new R();
		P	parsingPolicy;
		return parsingPolicy.parse(this, theTree, *theRule);
	}

	template <class R, class P>
	bool	loadRule(const std::string& compString, zia::api::DataTree& theTree = zia::api::DataTree())
	{
		IMPRule*	theRule = new R(compString);
		P	parsingPolicy;
		return parsingPolicy.parse(this, theTree, *theRule);
	}

	template <class R, class P>
	bool	loadRule(const std::string& string1, const std::string& string2, zia::api::DataTree& theTree = zia::api::DataTree())
	{
		IMPRule*	theRule = new R(string1, string2);
		P	parsingPolicy;
		return parsingPolicy.parse(this, theTree, *theRule);
	}

	bool	check(const std::string& compString)
	{
		if (this->_message.getCurMsg().find(compString) == 0)
			return true;
		return false;
	}

	bool	consume(const IMPRule& theRule)
	{
		this->_message.getCurMsg().erase(0, theRule.getNbrMatch());
		return true;
	}

/*	bool	readUntil(const std::string& ref, zia::api::DataTree& theTree = zia::api::DataTree(), int nbMatch = 1)
	{
		for (;nbMatch > 0; nbMatch--)
		{
			int	dist = this->getMessage().getCurMsg().find(ref);
			theTree.attribData(this->getMessage().getCurMsg().substr(0, dist));
			if (this->_mode == MPParser::CONSUME)
				this->_message.getCurMsg().erase(0, dist + ref.size());
			if (dist == -1)
				return false;
		}
		return true;
	}*/

	bool	separator()
	{
		return this->_options.parse(this);
	}

	MPMessage&	getMessage()
	{ return this->_message; }

	const MPMessage&	getConstMessage() const
	{ return this->_message; }

	void	switchMode(MPParser::ParsingMode newMode)
	{ this->_mode = newMode; }

	void	changeMessage(const std::string& message)
	{ this->_message.updateMessage(message); }

	MPParser::ParsingMode	mode() const
	{ return this->_mode; }


private:
	MPOption	_options;
	MPMessage	_message;
	MPParser::ParsingMode	_mode;


};

#endif /* __MPPARSER_H__ */