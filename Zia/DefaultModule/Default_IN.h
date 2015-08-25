#ifndef __DEFAULT_IN__
# define __DEFAULT_IN__

#include "api/IModule.hpp"
#include "api/IMessage.hpp"
#include "api/AStream.hpp"

namespace	zia {
	namespace	module {

class	Default_IN 
	: public zia::api::IModule
{
public:
	Default_IN();
	zia::api::AStream*	initStep(zia::api::IMessage& message, zia::api::AStream* inStream);
	int	execStep(zia::api::AStream& inStream);
	virtual void 	module_delete(zia::api::IConnection &connection);
private:
	zia::api::AStream*	_outStream;
	const static size_t	_buffSize;
};

	}
}

#endif