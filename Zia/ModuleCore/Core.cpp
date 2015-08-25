#include "Core.h"
#include "BasicStream.h"

Core::Core(void)
	: zia::api::IModule(), _outstream(0)
{
}

Core::~Core(void)
{
}

int					Core::test(zia::api::IStream&)
{
	return 0;
}


zia::api::IStream*	Core::stepIn(zia::api::IMessage& message, zia::api::IStream* input)
{
	this->_outstream = message.newDataStream();
	input->isClosed();
	//input->setReader(
	//	zia::api::IStream::Reader::create<Core, &Core::test>(this)
	//);
	return this->_outstream;
}

extern "C"
{
	zia::api::IModule*  module_new(std::list<zia::api::HttpStep::Pair>& stepsCallbacks,
		zia::api::IConnection& connection,
		zia::api::IConf& conf)
	{
				Core* core = new Core();
		stepsCallbacks.push_back(
			zia::api::HttpStep::Pair(zia::api::HttpStep::IN, 
			zia::api::HttpStep::Callback::create<Core, &Core::stepIn>(core.getStepOne()))
			);
		return core;
	}
}

