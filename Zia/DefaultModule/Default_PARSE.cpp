#include "Default_PARSE.h"

#include "MPPolicyMust.h"
#include "RequestHTTPMPRule.h"
#include "ReadStream.h"



zia::module::Default_PARSE::Default_PARSE()
	: _outStream(NULL)
{}

zia::module::Default_PARSE::~Default_PARSE()
{
	if (this->_outStream != NULL)
		delete this->_outStream;
}

void 	zia::module::Default_PARSE::module_delete(zia::api::IConnection &connection)
{}

zia::api::AStream*	zia::module::Default_PARSE::initStep(zia::api::IMessage& message, zia::api::AStream* inStream)
{
	this->_outStream = message.newDataStream();
	this->_message = &message;
	inStream->setReader(zia::api::AStream::Reader::create<zia::module::Default_PARSE, &zia::module::Default_PARSE::execStep>(this));
	return this->_outStream;

}


int	zia::module::Default_PARSE::execStep(zia::api::AStream& input)
{
	char	buffer[1040 + 1];
	zia::ReadStream::readAstream(input, this->_out, buffer, 1040);
	if (!this->_message->isParsed())
	{
		MPParser	parser(this->_out, MPParser::CONSUME);
		if (parser.loadRule<RequestHTTPMPRule, MPPolicyMust>(this->_message->http()) == false)
			return false;
		this->_out = parser.getMessage().getCurMsg();
	}
	this->_outStream->write(this->_out);
	this->_message->connection().close();
	return true;
}
