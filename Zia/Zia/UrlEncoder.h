#pragma once

#include <string>

namespace zia{
	namespace utils{
		class UrlEncoder
		{
			std::string	_encode;
			static const std::string	authorizedChar;	
		public:
			UrlEncoder(void);
			~UrlEncoder(void);
			UrlEncoder(const UrlEncoder&);
			UrlEncoder&	operator=(const UrlEncoder&);
			void	operator()(const char	c);
			const std::string&	urlEncode() const;
			static	std::string	urlEncode(const std::string&);
		};
	};
};

