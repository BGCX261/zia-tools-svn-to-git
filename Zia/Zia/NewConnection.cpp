#include <iostream>
#include <algorithm>
#include "NewConnection.h"
#include "AllocateModule.h"
#include "AcceptorTcp.h"
#include "ConnectionBase.h"
#include "Linker.h"


zia::core::NewConnection::NewConnection()
{


}

zia::core::NewConnection::~NewConnection(void)
{
	//if (this->_ziaMessage)
//		delete this->_ziaMessage;
}

zia::core::NewConnection&  zia::core::NewConnection::operator=(const zia::core::NewConnection& other)
{
	this->_listLoad = other._listLoad;
	this->_listUnload = other._listUnload;
	return *this;
}

zia::core::NewConnection::NewConnection(const zia::core::NewConnection& other)
	:  _listLoad(other._listLoad), _listUnload(other._listUnload)
{

}

int											zia::core::NewConnection::startWrite(zia::api::AStream& inStream)
{
	char buffer[500];
	int nb_read;
	while ((nb_read = inStream.read(buffer, 500)) > 0)
	{
		this->_client.send(buffer, nb_read);
	}
	return zia::api::ZIA_OK;
}

void	zia::core::NewConnection::startRead()
{
	std::string	buff;
	buff.resize(1024);
	this->_linker.lastStream()->setReader(zia::api::AStream::Reader::create<zia::core::NewConnection, &zia::core::NewConnection::startWrite>(this));
	while(this->_client.isOpen())
	{
//		std::cout << "Socket open : " << std::boolalpha << this->_client.isOpen() << std::endl;
		if (this->_client.avaible() > 0)
		{
			size_t	readed = this->_client.recv(buff);
			buff[readed] = '\0';
			this->_linker.stream()->write(buff);
			buff.clear();
			buff.resize(1024);
		}
	}
}

void	zia::core::NewConnection::operator()(const ip::tcp::socket& socket)
{
	try{
	this->_client = socket;
	this->_connectionBase.socket(this->_client);
	this->_allocator.connection(&this->_connectionBase);
	this->_allocator = std::for_each(this->_listLoad.begin(), this->_listLoad.end(), this->_allocator);
	this->_allocator.sort();
	std::list<zia::api::HttpStep::Pair> callback = this->_allocator.stepCallback();
	this->_ziaMessage = new zia::ZiaMessage(this->_connectionBase);
	this->_linker.message(this->_ziaMessage);
	this->_linker = std::for_each(callback.begin(), callback.end(), this->_linker);
	this->startRead();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		this->_client.close();
	}
}

void	zia::core::NewConnection::handlerUnLoad(const std::list<zia::api::HandlerModuleUnload>& listUnload)
{
	this->_listUnload = listUnload;
}

void	zia::core::NewConnection::handlerLoad(const std::list<zia::api::HandlerModule>& listLoad)
{
	this->_listLoad = listLoad;
}