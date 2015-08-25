#pragma once

#include "api/AStream.hpp"

namespace zia
{
	class ReadStream
	{
	public:
		static	void	readAstream(zia::api::AStream& input, std::string&	dest, char* from, const size_t buffsize);
	};
};