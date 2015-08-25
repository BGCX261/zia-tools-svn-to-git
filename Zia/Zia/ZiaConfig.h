#pragma once

#include "api/IConf.hpp"
#include "api/DataTree.hpp"

namespace zia{

	class ZiaConfig
		: public zia::api::IConf
	{
		ZiaConfig(void);
		static ZiaConfig*	_instance;
	public:
		~ZiaConfig(void);
		void	loadFromConfFile(const std::string& confile);
		bool	loadContentType(const std::string& path);
		bool	loadStatusCode(const std::string& path);
		static ZiaConfig*	getInstance(); 
	};

}
