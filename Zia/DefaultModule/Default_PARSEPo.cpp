#include "Default_PARSEPo.h"

#include "RequestHTTPMPRule.h"
#include "ReadStream.h"
#include "TimeFormat.h"

#include "MPParser.hpp"
#include "MPPolicyMust.h"

zia::module::Default_PARSEPo::Default_PARSEPo()
	: _outStream(NULL)
{
}

zia::module::Default_PARSEPo::~Default_PARSEPo()
{
	if (this->_outStream != NULL)
		delete this->_outStream;
}

void 	zia::module::Default_PARSEPo::module_delete(zia::api::IConnection &connection)
{}

zia::api::AStream*	zia::module::Default_PARSEPo::initStep(zia::api::IMessage& message, zia::api::AStream* inStream)
{
	this->_message = &message;
	this->_outStream = message.newDataStream();
	inStream->setReader(zia::api::AStream::Reader::create<zia::module::Default_PARSEPo, &zia::module::Default_PARSEPo::execStep>(this));
	return this->_outStream;
}

int	zia::module::Default_PARSEPo::execStep(zia::api::AStream& input)
{
	if (this->_message->http()["Header"].has("Transfer-Encoding") && this->_message->http()["Header"]["Transfer-Encoding"].v().compare("chunked"))
	{
		std::cout << "ALARM !! Chunked Request" << std::endl;
		const size_t	buffSize = 2000;
		char	buffer[buffSize];
		zia::ReadStream::readAstream(input, this->_out, buffer, buffSize);
		
		MPParser	parser(this->_out, MPParser::CONSUME);
		if (parser.loadRule<RequestHTTPMPRule, MPPolicyMust>(this->_message->http()) == false)
			return false;
		this->_out = parser.getMessage().getCurMsg();
	}
	this->_outStream->flush();
	return true;
}
