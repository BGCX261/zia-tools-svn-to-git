#include "DocumentRoot.h"
#include <string>
#include <iostream>
#include "InvalidFile.hpp"
#include <sstream>

int	main()
{

	filesystem::FilePath path =  filesystem::FilePath::toValidPath("D:/Dev/Libs/boost/");
	filesystem::DocumentRoot	documentroot;
	documentroot.set(path);
	filesystem::BasicFile file = documentroot.get("boost_1_45_0/bin.v2/libs/filesystem/build/msvc-10.0/debug/link-static/threading-multi/libboost_filesystem-vc100-mt-gd-1_45.lib.rsp");
	if (file == filesystem::ErrorFile<filesystem::BasicFile>::invalid())
		std::cerr << "File invalide" << std::endl;
	std::ifstream stream = file.ifstream();
	char * buffer;
	buffer = new char [100];
	stream.get();
	std::cout << stream.gcount() << std::endl;
	std::cout << buffer << std::endl;
	return true;
}