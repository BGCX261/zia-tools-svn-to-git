#ifndef __DEFAULT_RAW_H__
# define __DEFAULT_RAW_H__

#include <string>


#include "api/IModule.hpp"
#include "api/IMessage.hpp"
#include "api/AStream.hpp"
#include "api/IConf.hpp"

namespace	zia {
	namespace	module {


class	Default_RAW : public api::IModule
{
public:
	Default_RAW(zia::api::IConf* conf);
	virtual ~Default_RAW();
	api::AStream*	initStep(zia::api::IMessage& message, zia::api::AStream* inStream);
	int	execStep(zia::api::AStream& inStream);
	virtual void 	module_delete(zia::api::IConnection &connection);

private:
	
	void	concatHttpResp(const zia::api::DataTree& theTree);
	void	responseLine();
	
	zia::api::AStream*	_outStream;
	std::string	_headerResp;
	zia::api::IMessage*	_message;
	zia::api::IConf*const _conf;
};


	}
}

#endif /* __DEFAULT_RAW_H__ */
