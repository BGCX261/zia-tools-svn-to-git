#include "Default_Module.h"

zia::module::Default_Module::Default_Module(zia::api::IConf* conf)
	: _ex(conf), _raw(conf)
{}

void 	zia::module::Default_Module::module_delete(zia::api::IConnection &connection)
{}