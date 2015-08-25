#include "ValidSeparator.h"


ValidSeparator::ValidSeparator(const std::string& separator)
	: _validSeparator(separator)
{


}

ValidSeparator::ValidSeparator(const char c)
	: _validSeparator(&c)
{

}


ValidSeparator::~ValidSeparator(void)
{
}

bool	ValidSeparator::operator()(char c) const
{
	return !(this->_validSeparator.find_first_of(c) == std::string::npos);
}