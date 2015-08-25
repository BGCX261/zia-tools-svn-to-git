#ifndef __Default_PARSEPO_H__
# define __Default_PARSEPO_H__

#include <string>


#include "api/IModule.hpp"
#include "api/IMessage.hpp"
#include "api/AStream.hpp"

namespace	zia {
	namespace	module {


class	Default_PARSEPo : public api::IModule
{
public:
	Default_PARSEPo();
	virtual ~Default_PARSEPo();
	api::AStream*	initStep(zia::api::IMessage& message, zia::api::AStream* inStream);
	int	execStep(zia::api::AStream& inStream);
	virtual void 	module_delete(zia::api::IConnection &connection);

private:
	zia::api::AStream*	_outStream;
	std::string	_headerResp;
	zia::api::IMessage*	_message;
	std::string	_out;
};


	}
}

#endif /* __Default_PARSEPO_H__ */
