#include <algorithm>
#include <iterator>
#include <vector>
#include "BasicStream.h"


zia::BasicStream::BasicStream()
	: zia::api::AStream()
{

}


zia::BasicStream::~BasicStream()
{

}

int         zia::BasicStream::callReader()
{
	return this->mReader(*this);
}

bool        zia::BasicStream::canRead() const
{
	return true;
}

void        zia::BasicStream::write(const std::string& str)
{
	this->_buffer.append(str);
	this->flush();
}

void        zia::BasicStream::write(const char* buff, size_t buffSize)
{
	this->_buffer.append(buff, buffSize);
	this->flush();
}

size_t      zia::BasicStream::read(char* buff, size_t maxBuffSize)
{

	if (this->_buffer.size() > maxBuffSize)
	{
		std::swap_ranges(this->_buffer.begin(), this->_buffer.begin() + maxBuffSize, buff);
		this->_buffer.erase(0, maxBuffSize);
		return maxBuffSize;
	}
	else if (this->_buffer.size() == 0)
		return 0;
	else
	{
		size_t	temp = this->_buffer.size();
		std::swap_ranges(this->_buffer.begin(), this->_buffer.end(), buff);
		this->_buffer.clear();
		return temp;
	}
}

void        zia::BasicStream::drop()
{
	this->_buffer.clear();
}

void        zia::BasicStream::dropAll()
{
	this->drop();
	this->mReader.clear();
}

void        zia::BasicStream::flush()
{
	this->mReader(*this);
}

void        zia::BasicStream::close()
{	
	this->mClosed = true;
}

void        zia::BasicStream::forceClose()
{
	this->close();
}