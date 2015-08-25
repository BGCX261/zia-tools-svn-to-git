#include <list>

#include "Default_Module.h"

#include "api/IModule.hpp"
#include "api/IConf.hpp"
#include "api/HttpStep.hpp"
#include "api/AStream.hpp"





extern "C" 
{
	__declspec(dllexport)  zia::api::IModule*  module_new(std::list<zia::api::HttpStep::Pair>& stepsCallbacks,
		zia::api::IConnection& connection,
		zia::api::IConf& conf)
	{
		zia::module::Default_Module*      Dmodule = new zia::module::Default_Module(&conf);

		stepsCallbacks.push_back(zia::api::HttpStep::Pair(zia::api::STEP_IN_POST,
			zia::api::HttpStep::Callback::create<zia::module::Default_IN, &zia::module::Default_IN::initStep>(&Dmodule->_in)));
		stepsCallbacks.push_back(zia::api::HttpStep::Pair(zia::api::STEP_PARSER,
			zia::api::HttpStep::Callback::create<zia::module::Default_PARSE, &zia::module::Default_PARSE::initStep>(&Dmodule->_parse)));
		stepsCallbacks.push_back(zia::api::HttpStep::Pair(zia::api::STEP_PARSER_POST,
			zia::api::HttpStep::Callback::create<zia::module::Default_PARSEPo, &zia::module::Default_PARSEPo::initStep>(&Dmodule->_chunk)));
		stepsCallbacks.push_back(zia::api::HttpStep::Pair(zia::api::STEP_EXEC,
			zia::api::HttpStep::Callback::create<zia::module::Default_EX, &zia::module::Default_EX::initStep>(&Dmodule->_ex)));
		stepsCallbacks.push_back(zia::api::HttpStep::Pair(zia::api::RAWER,
			zia::api::HttpStep::Callback::create<zia::module::Default_RAW, &zia::module::Default_RAW::initStep>(&Dmodule->_raw)));
		stepsCallbacks.push_back(zia::api::HttpStep::Pair(zia::api::STEP_OUT_PRE,
			zia::api::HttpStep::Callback::create<zia::module::Default_OUTPr, &zia::module::Default_OUTPr::initStep>(&Dmodule->_outpr)));
		return (Dmodule);
	}
}