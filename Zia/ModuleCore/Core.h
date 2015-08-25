#pragma once


#define	DLEXPORT	__declspec(dllexport)
#define	DLIMPORT	__declspec(dllimport)

#include "api/init.hpp"
#include "api/IModule.hpp"
#include "api/IMessage.hpp"
#include "api/IStream.hpp"

class Core
	: public zia::api::IModule
{
private:
	 zia::api::IStream*       _outstream;
public:
	Core(void);
	~Core(void);
	zia::api::IStream*	stepIn(zia::api::IMessage&, zia::api::IStream*);
	int					test(zia::api::IStream&);

};

