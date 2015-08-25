#ifndef __DEFAULT_MODULE_H__
# define __DEFAULT_MODULE_H__

#include "Default_EX.h"
#include "Default_IN.h"
#include "Default_OUTPr.h"
#include "Default_PARSE.h"
#include "Default_PARSEPo.h"
#include "Default_RAW.h"

namespace	zia {
	namespace	module {

class	Default_Module : public zia::api::IModule
{
public:
	zia::module::Default_EX	_ex;
	zia::module::Default_IN	_in;
	zia::module::Default_OUTPr	_outpr;
	zia::module::Default_PARSE	_parse;
	zia::module::Default_RAW	_raw;
	zia::module::Default_PARSEPo	_chunk;
	Default_Module(zia::api::IConf*	conf);
	virtual void 	module_delete(zia::api::IConnection &connection);
};

	}
}

#endif /* __DEFAULT_MODULE_H__ */