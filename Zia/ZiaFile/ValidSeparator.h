#pragma once

#include <string>

#ifndef WIN_32
	#define PATH_SEPARATOR '\\'
	#define INVALID_PATH_SEPARATOR '/'
#else
	#define PATH_SEPARATOR  '/'
	#define INVALID_PATH_SEPARATOR '\'
#endif

class ValidSeparator
{
	std::string	_validSeparator;

public:
	ValidSeparator(const std::string& separator);
	ValidSeparator(const char c);
	~ValidSeparator(void);
	bool	operator()(char c) const;
};

