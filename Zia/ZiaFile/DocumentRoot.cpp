#include "DocumentRoot.h"
#include <Windows.h>
#include <exception>
#include <iostream>
#include "InvalidFile.hpp"


filesystem::DocumentRoot::DocumentRoot()
	: _dir()
{

}

filesystem::DocumentRoot::~DocumentRoot(void)
{

}

filesystem::DocumentRoot::DocumentRoot(const  DocumentRoot& other)
	: _dir(other._dir)
{

}

const filesystem::BasicFile&	filesystem::DocumentRoot::is() const
{
	return this->_dir;
}

void		filesystem::DocumentRoot::set(const filesystem::FilePath& dirpath)
{
	this->_dir = dirpath;
	std::auto_ptr<std::string>	error_string(new std::string(this->_dir.path().toString() 
											+ " is not a valid directory"));
	if (this->_dir.type() != filesystem::info::DIRECTORY)
	{
		this->_dir = filesystem::BasicFile();
		std::exception e(error_string->c_str());
		throw std::exception(e);
	}
}

const	filesystem::BasicFile  filesystem::DocumentRoot::get(const std::string& key) const
{
	FilePath valide;
	valide += this->_dir.path();
	valide += FilePath::toValidPath(key);
	return  filesystem::BasicFile(valide);
}