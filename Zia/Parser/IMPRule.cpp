#include "IMPRule.h"

IMPRule::IMPRule()
: _nbrMatch(0)
{}

size_t	IMPRule::getNbrMatch() const
{
	return this->_nbrMatch;
}
