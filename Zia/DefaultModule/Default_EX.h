#ifndef __DEFAULT_EX_H__
# define __DEFAULT_EX_H__

#include <string>

#include "api/IModule.hpp"
#include "api/IMessage.hpp"
#include "api/AStream.hpp"
#include "api/IConf.hpp"

#include "DocumentRoot.h"

namespace	zia {
	namespace	module {


class	Default_EX : public api::IModule
{
public:
	Default_EX(zia::api::IConf* conf);
	virtual ~Default_EX();
	api::AStream*	initStep(zia::api::IMessage& message, zia::api::AStream* inStream);
	int	execStep(zia::api::AStream& inStream);
	virtual void 	module_delete(zia::api::IConnection &connection);

private:

	bool	openFile(const filesystem::DocumentRoot& file, zia::api::AStream& input);

	zia::api::AStream*	_outStream;
	zia::api::IMessage* _message;
	std::string	_path;
	zia::api::IConf*const	_conf;
};


	}
}

#endif /* __DEFAULT_EX_H__ */
