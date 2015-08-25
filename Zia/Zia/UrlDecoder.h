#pragma once

#include <string>

namespace zia{
	namespace utils{
		class UrlDecoder
		{
		public:
			static	std::string decode(const std::string& url);
		};
	};
};