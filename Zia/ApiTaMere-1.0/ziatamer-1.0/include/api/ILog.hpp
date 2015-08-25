#ifndef _ZIA_API_ILOG_H_
#define _ZIA_API_ILOG_H_

#include <sstream>
#include <iostream>

#include "defines.hpp"

namespace zia{
	namespace api{
		enum LogLevel
		{
			LOG_ASSERT = 1,
			LOG_ERR,
			LOG_WARN,
			LOG_INFO,
			LOG_DEBUG,
			LOG_DEBUG2
		};

		class ILog
		{
		public:
			ILog();
			virtual ~ILog();
			ILog&               operator << (std::ostream& (*pf)(std::ostream&));
			template <typename T>
			ILog&               operator << (const T& input)
			{
				mLine << input;
				return (*this);
			}
			virtual api::ILog&  operator << (api::LogLevel level) = 0;
			virtual void        flush() = 0;
			virtual void        print(api::LogLevel level, const std::string& format, ...) = 0;

		protected:
			std::stringstream   mLine;

		};

	};
};

#endif /* _ZIA_API_ILOG_H_ */
