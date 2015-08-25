#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "Zia.h"
#include "ZiaConfig.h"

void	wait()
{
	std::cout << "put a button for stop an application" << std::endl;
	std::getline(std::cin, std::string());
}


int	main()
{
	//zia::api::DataTree	tree;
	//tree["toto"] = "tata";
	//tree["toto"] = "baba";
	//tree["toto"].print(std::cout);
	
	try
	{
		zia::ZiaConfig*	confeur = zia::ZiaConfig::getInstance();
		confeur->loadFromConfFile("C:/www/conf/");

		std::cout << "Zia server start ..." << std::endl;
		zia::Zia	z;
		z.start();
	}
	catch(const std::exception& e)
	{
		std::cout << "Last error: " << e.what() << std::endl;
	}
	wait();
	return true;


}