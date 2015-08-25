#ifndef __DEFAULT_OUTPr_H__
# define __DEFAULT_OUTPr_H__

#include "api/IModule.hpp"
#include "api/IMessage.hpp"
#include "api/AStream.hpp"

namespace	zia {
	namespace	module {


class	Default_OUTPr : public api::IModule
{
public:
	Default_OUTPr();
	virtual ~Default_OUTPr();
	api::AStream*	initStep(zia::api::IMessage& message, zia::api::AStream* inStream);
	int	execStep(zia::api::AStream& inStream);
	virtual void 	module_delete(zia::api::IConnection &connection);

private:
	zia::api::AStream*	_outStream;
	zia::api::IConnection*	_connection;
	const static size_t	_buffSize;
	std::string	_inString;
};


	}
}

#endif /* __DEFAULT_OUTPr_H__ */
