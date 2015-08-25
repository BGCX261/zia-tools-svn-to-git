#include "FilePath.h"
#include <algorithm>

filesystem::FilePath::FilePath(const std::string& path)
{
	this->set(path);
}

filesystem::FilePath::FilePath(void)
{

}

filesystem::FilePath::~FilePath(void)
{

}

filesystem::FilePath::FilePath(const FilePath& other)
	: _path(other._path)
{


}

filesystem::FilePath& filesystem::FilePath::operator=(const FilePath& other)
{
	this->_path = other._path;
	return *this;
}

filesystem::FilePath& filesystem::FilePath::operator=(const std::string& path)
{
	this->set(path);
	return *this;
}

const std::string&	filesystem::FilePath::toString() const
{
	return this->_path;
}

void	filesystem::FilePath::set(const std::string& path)
{
	this->_path = path;
	
}

std::string filesystem::FilePath::basename(char separator) const
{
	return this->_path.substr(this->_path.rfind(separator) + 1);
}

std::string filesystem::FilePath::dirname(char separator) const
{
	return this->_path.substr(0, this->_path.rfind(separator));
}


filesystem::FilePath	filesystem::FilePath::toValidPath(const std::string& path)
{
	std::string tmp_path = path;
	std::replace_if(tmp_path.begin(), tmp_path.end(), ValidSeparator(INVALID_PATH_SEPARATOR), PATH_SEPARATOR);
	if (tmp_path.back() == PATH_SEPARATOR)
		tmp_path.erase(tmp_path.end());
	return FilePath(tmp_path);
}

bool	filesystem::FilePath::operator==(const FilePath& filepath) const
{
	return this->_path.compare(filepath._path) == 0;
}

bool	filesystem::FilePath::operator==(const std::string& filepath) const
{
	return this->_path.compare(filepath) == 0;
}

bool	filesystem::FilePath::operator!=(const filesystem::FilePath& filepath) const
{
	return !(*this == filepath);
}

bool	filesystem::FilePath::operator!=(const std::string& filepath) const
{
	return !(*this == filepath);
}

filesystem::FilePath& filesystem::FilePath::operator+=(const FilePath& other)
{
	this->set(this->_path + other._path);
	return *this;
}


