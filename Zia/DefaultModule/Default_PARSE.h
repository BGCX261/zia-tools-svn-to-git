#ifndef __DEFAULT_PARSE_H__
# define __DEFAULT_PARSE_H__

#include <string>

#include "api/IModule.hpp"
#include "api/IMessage.hpp"
#include "api/AStream.hpp"

#include "MPParser.hpp"

namespace	zia {
	namespace	module {


class	Default_PARSE : public api::IModule
{
public:
	Default_PARSE();
	virtual ~Default_PARSE();
	api::AStream*	initStep(zia::api::IMessage& message, zia::api::AStream* inStream);
	int	execStep(zia::api::AStream& inStream);
	virtual void 	module_delete(zia::api::IConnection &connection);

private:
	zia::api::AStream*	_outStream;
	std::string	_out;
	zia::api::IMessage*	_message;
};


	}
}

#endif /* __DEFAULT_PARSE_H__ */
