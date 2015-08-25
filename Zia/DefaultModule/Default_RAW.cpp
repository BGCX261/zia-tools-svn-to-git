#include "Default_RAW.h"

#include "MPPolicyMust.h"
#include "RequestHTTPMPRule.h"
#include "ReadStream.h"
#include "TimeFormat.h"


zia::module::Default_RAW::Default_RAW(zia::api::IConf* conf)
	: _outStream(NULL), _conf(conf)
{}

zia::module::Default_RAW::~Default_RAW()
{
	if (this->_outStream != NULL)
		delete this->_outStream;
}

void 	zia::module::Default_RAW::module_delete(zia::api::IConnection &connection)
{}

zia::api::AStream*	zia::module::Default_RAW::initStep(zia::api::IMessage& message, zia::api::AStream* inStream)
{
	this->_message = &message;
	this->_outStream = message.newDataStream();
	inStream->setReader(zia::api::AStream::Reader::create<zia::module::Default_RAW, &zia::module::Default_RAW::execStep>(this));
	return this->_outStream;
}

void	zia::module::Default_RAW::responseLine()
{
	this->_headerResp.clear();
	this->_headerResp = this->_message->http()["Request-Line"]["HTTP-Version"].v() + " "	// Version (HTML/*.*)
		+ this->_message->httpResp()["Status-Line"]["Status-Code"].v() + " "				// Status Code (ex: 200, 404 ...)
		+ (*this->_conf)["StatusCode"][this->_message->httpResp()["Status-Line"]["Status-Code"].v()].v() // Description ligne (ex: OK, Not Found ...)
		+ "\r\n";
	std::cout << "Header de Sortie : " << this->_headerResp << std::endl;
}

void	zia::module::Default_RAW::concatHttpResp(const zia::api::DataTree& theTree)
{	// Ajoute tous les elements enregistrés dans le header de sortie à une string
	this->responseLine();
	std::map<std::string, zia::api::DataTree>::const_iterator	it = theTree["Header"].mSubs.begin();
	for (; it != theTree["Header"].mSubs.end(); it++)
	{
		this->_headerResp += (*it).first + ":" + (*it).second.v() + "\r\n";
	}
	this->_headerResp += "\r\n";
}

int	zia::module::Default_RAW::execStep(zia::api::AStream& input)
{
	const size_t	BuffSize = 2048;
	char	buffer[BuffSize + 1];
	if (this->_headerResp.empty())
	{
		std::string	out;
		this->_message->httpResp()["Header"]["Date"] = TimeFormat::getCurrentTime();
		this->_message->httpResp()["Header"]["Connection"] = "Close";
		this->concatHttpResp(this->_message->httpResp());
		this->_outStream->write(this->_headerResp);

	}
	size_t	size;
	while ((size = input.read(buffer, BuffSize)) > 0)
	{
		this->_outStream->write(buffer, size);
	}
	return true;
}
