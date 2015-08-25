#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "api/ILog.hpp"

namespace zia{

		class Printer
			: public zia::api::ILog
		{
		private:
			api::LogLevel						_lvl;
			std::vector<std::string>	_stringLvl;
		public:
			Printer(void);
			~Printer(void);
			virtual void        print(api::LogLevel level, const std::string& format, ...);
			virtual void        flush();
		};
};