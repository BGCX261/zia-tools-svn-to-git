#include "AcceptorTcp.h"
#include "Zia.h"
#include "NewConnection.h"
#include "BinderTask.h"
#include "bind.hpp"

zia::Zia::Zia(void)
	: _finder(), _pool(250)
{
	this->_finder.addModule("DefaultModule.dll");
	this->_acceptors.push_back(new ip::tcp::AcceptorTcp(ip::tcp::endpoint(ip::Address::fromString("192.168.1.30"), 80)));
}

zia::Zia::~Zia(void)
{
	this->_finder.allHandlerUnload();
}


void	zia::Zia::loopConnection(int i)
{
	try
	{
		std::cout << "En attente de connection..." << std::endl;
		ip::tcp::socket	new_client;	
		this->_acceptors.front()->accept(new_client);
		zia::core::NewConnection new_connection;
		new_connection.handlerLoad(this->_finder.allHandlerModule());
		new_connection.handlerUnLoad(this->_finder.allHandlerModuleUnload());
		this->_pool.addTask(new thread::BinderTask(binder::bind(&core::NewConnection::operator(), new_connection, new_client)));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	this->_pool.addTask(new thread::BinderTask(binder::bind(&Zia::loopConnection, this, 0)));
}

void	zia::Zia::start()
{
	this->_finder.allHandlerLoad();
	this->_pool.addTask(new thread::BinderTask(binder::bind(&Zia::loopConnection, this, 0)));
	this->_finder.allHandlerModuleUnload();
	std::getline(std::cin, std::string());
	this->_pool.join();
}