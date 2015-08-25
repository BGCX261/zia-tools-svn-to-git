#include "BasicFile.h"
#include <windows.h>

filesystem::BasicFile::BasicFile(void)
	: _filePath(), _infos(INVALID_FILE_ATTRIBUTES)
{

}

filesystem::BasicFile::BasicFile(const std::string& filename)
	: _filePath(filename)
{
	this->getFileInfos();
}

filesystem::BasicFile::~BasicFile(void)
{

}

filesystem::BasicFile::BasicFile(const filesystem::BasicFile& other)
	: _filePath(other._filePath), _infos(other._infos)
{

}


filesystem::BasicFile::BasicFile(const filesystem::FilePath& filename)
	: _filePath(filename)
{
	this->getFileInfos();
}

void	filesystem::BasicFile::path(const std::string& filename)
{
	this->_filePath = filename;
	this->getFileInfos();
}


const filesystem::FilePath&	filesystem::BasicFile::path() const
{
	return this->_filePath;
}

filesystem::BasicFile&	filesystem::BasicFile::operator=(const BasicFile& other)
{
	this->_filePath = other._filePath;
	this->_infos = other._infos;
	return *this;
}

filesystem::BasicFile&	filesystem::BasicFile::operator=(const std::string& path)
{
	this->_filePath.set(path);
	this->getFileInfos();
	return *this;
}

filesystem::BasicFile&	filesystem::BasicFile::operator=(const FilePath& filepath)
{
	this->_filePath = filepath;
	this->getFileInfos();
	return *this;
}


filesystem::info::type	filesystem::BasicFile::type() const
{
	filesystem::info::type	type;

	switch (this->_infos)
	{
	case FILE_ATTRIBUTE_DIRECTORY:
		type = filesystem::info::DIRECTORY;
		break;

	case INVALID_FILE_ATTRIBUTES:
		type = filesystem::info::NONE;
		break;

	default:
		type = filesystem::info::REGULAR_FILE;
		break;
	}
	return type;
}

void	filesystem::BasicFile::getFileInfos()
{
	this->_infos = GetFileAttributes(this->_filePath.toString().c_str());
}


std::fstream	filesystem::BasicFile::fstream(std::ios_base::openmode	mode) const
{
	return std::fstream(this->_filePath.toString().c_str(), mode);
}

std::ifstream   filesystem::BasicFile::ifstream(std::ios_base::openmode mode) const
{
	return std::ifstream(this->_filePath.toString().c_str(), mode);
}

bool	filesystem::BasicFile::operator==(const BasicFile& other) const
{
	return this->_filePath == other._filePath && this->_infos == other._infos;
}

bool	filesystem::BasicFile::operator!=(const BasicFile& other) const
{
	return !(*this == other);
}