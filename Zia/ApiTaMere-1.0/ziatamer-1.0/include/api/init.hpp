#ifndef _INITDLL_H_
#define _INITDLL_H_

#include <list>

#include "IModule.hpp"
#include "IConf.hpp"
#include "HttpStep.hpp"
#include "AStream.hpp"

extern "C"
{
    void                dll_load(zia::api::IConf& conf,
                                 zia::api::ILog& log);
    zia::api::IModule*  module_new(std::list<zia::api::HttpStep::Pair>& stepsCallbacks,
                                   zia::api::IConnection& connection,
                                   zia::api::IConf& conf);
    void                dll_unload(zia::api::ILog& log);
}

#endif /* _INITDLL_H_ */
