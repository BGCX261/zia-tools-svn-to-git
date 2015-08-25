#include "Default_OUTPr.h"
#include <algorithm>
#include "ReadStream.h"

const size_t zia::module::Default_OUTPr::_buffSize = 10;

zia::module::Default_OUTPr::Default_OUTPr()
	: _outStream(NULL)
{}

zia::module::Default_OUTPr::~Default_OUTPr()
{
	if (this->_outStream != NULL)
		delete this->_outStream;
}

void 	zia::module::Default_OUTPr::module_delete(zia::api::IConnection &connection)
{}

zia::api::AStream*	zia::module::Default_OUTPr::initStep(zia::api::IMessage& message, zia::api::AStream* inStream)
{
	this->_outStream = message.newDataStream();
	this->_connection = &message.connection();
	inStream->setReader(zia::api::AStream::Reader::create<zia::module::Default_OUTPr, &zia::module::Default_OUTPr::execStep>(this));
	return this->_outStream;
}

int	zia::module::Default_OUTPr::execStep(zia::api::AStream& input)
{

	const size_t	BuffSize = 3000;
	char	buffer[BuffSize + 1];
	size_t size;
	while ((size = input.read(buffer, BuffSize)) > 0)
	{
		buffer[size] = '\0';
		this->_outStream->write(buffer, size);
	}
	this->_outStream->close();
	return true;
}
