#include "Default_in.h"
#include "ReadStream.h"

const size_t zia::module::Default_IN::_buffSize = 13;

zia::module::Default_IN::Default_IN()
	: _outStream(0)
{}

void 	zia::module::Default_IN::module_delete(zia::api::IConnection &connection)
{}

zia::api::AStream*	zia::module::Default_IN::initStep(zia::api::IMessage& message, zia::api::AStream* inStream)
{
	zia::api::IMessage* msg = &message;
	zia::api::DataTree&	info = message.connection().info();
	if (info["connection"]["local"]["port"] == "80")
	{
		this->_outStream = message.newDataStream();
		inStream->setReader(zia::api::AStream::Reader::create<zia::module::Default_IN, &zia::module::Default_IN::execStep>(this));
		return this->_outStream;
	}
	return inStream;
}

int	zia::module::Default_IN::execStep(zia::api::AStream& inStream)
{
	char	buffer[300 + 1];
	std::string	out;
	zia::ReadStream::readAstream(inStream, out, buffer, 300);
	this->_outStream->write(out);
	return true;
}