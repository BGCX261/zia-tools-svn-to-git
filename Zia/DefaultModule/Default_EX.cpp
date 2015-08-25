#include "Default_EX.h"


extern filesystem::DocumentRoot* documentRoot;

zia::module::Default_EX::Default_EX(zia::api::IConf* conf)
	: _outStream(NULL), _conf(conf)
{
}

zia::module::Default_EX::~Default_EX()
{
	if (this->_outStream != NULL)
		delete this->_outStream;
}

void 	zia::module::Default_EX::module_delete(zia::api::IConnection &connection)
{}

zia::api::AStream*	zia::module::Default_EX::initStep(zia::api::IMessage& message, zia::api::AStream* inStream)
{
	this->_message = &message;
	this->_outStream = message.newDataStream();
	inStream->setReader(zia::api::AStream::Reader::create<zia::module::Default_EX, &zia::module::Default_EX::execStep>(this));
	return this->_outStream;
}

bool	zia::module::Default_EX::openFile(const filesystem::DocumentRoot& file, zia::api::AStream& input)
{
	std::ifstream	myStream;
	myStream = file.get(this->_message->http()["Request-Line"]["Request-URI"].v()).ifstream(std::fstream::binary);
	this->_message->httpResp()["Status-Line"]["Status-Code"] = "200";

	myStream.seekg (0, std::ios::end);
	std::ostringstream	flux;
	flux << myStream.tellg();
	myStream.seekg (0, std::ios::beg);

	this->_message->httpResp()["Header"]["Content-Length"] = flux.str();
	this->_message->httpResp()["Header"]["Content-Type"] = (*this->_conf)["ContentType"][this->_message->http()["Request-Line"]["Request-URI"]["Extention"].v()].v();

	if (this->_message->http()["Request-Line"]["Method"].v().compare("HEAD") != 0)
	{
		const size_t	BuffSize = 2048;
		char	buffer[BuffSize];
		while (myStream.good() == true)
		{
			myStream.read(buffer, BuffSize);
			this->_outStream->write(buffer, myStream.gcount());

		}
	}
	return true;	
}

int	zia::module::Default_EX::execStep(zia::api::AStream& input)
{
	if (this->_message->httpResp()["Status-Line"].has("Status-Code"))
		this->_outStream->flush();
	else if ((*this->_conf)["ContentType"].has(this->_message->http()["Request-Line"]["Request-URI"]["Extention"].v()) || this->_message->http()["Request-Line"]["Request-URI"]["Extention"].v().empty())
	{
		filesystem::DocumentRoot	file;
		file.set(filesystem::FilePath::toValidPath("C:/www/"));
		if (file.get(this->_message->http()["Request-Line"]["Request-URI"].v()).type() == filesystem::info::NONE)
		{	// Si le fichier n'existe pas, envoit d'un 404 not found
			this->_message->httpResp()["Status-Line"]["Status-Code"] = "404";
			this->_outStream->flush();
			return false;
		}
		else if (file.get(this->_message->http()["Request-Line"]["Request-URI"].v()).type() == filesystem::info::DIRECTORY)
		{	// Si répertoire, on redirige vers ./index.html
			this->_message->http()["Request-Line"]["Request-URI"] = this->_message->http()["Request-Line"]["Request-URI"].v() + "/index.html";
			this->_message->http()["Request-Line"]["Request-URI"]["Extention"] = "html";
			input.flush();
			return true;
		}
		else
			return this->openFile(file, input);
	}
	else  // On ne connait pas l'extention, code 501 Non Implémenté
	{
		this->_message->httpResp()["Status-Line"]["Status-Code"] = "501";
		this->_outStream->flush();
	}
	return false;
}
