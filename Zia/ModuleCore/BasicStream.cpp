#include <iostream> 
#include <algorithm>
#include "BasicStream.h"


BasicStream::BasicStream()
{

}


BasicStream::~BasicStream()
{

}

int         BasicStream::callReader()
{
	return this->mReader(*this);
}

bool        BasicStream::canRead() const
{
	return this->_buffer.empty();
}

void        BasicStream::write(const std::string& str)
{
	this->_buffer.append(str);
	if (this->_buffer.size() >= this->mExpectedSize)
		this->flush();
}

void        BasicStream::write(const char* buff, size_t buffSize)
{
	this->_buffer.append(buff, buffSize);
	if (this->_buffer.size() >= this->mExpectedSize)
		this->flush();
}

size_t      BasicStream::read(char* buff, size_t maxBuffSize)
{
	if (this->_buffer.size() > maxBuffSize)
	{
		std::copy(this->_buffer.begin(), this->_buffer.begin() + maxBuffSize,  buff);
		this->_buffer.erase(0, maxBuffSize);
		return maxBuffSize;
	}
	std::copy(this->_buffer.begin(), this->_buffer.end(), buff);
	maxBuffSize = this->_buffer.size();
	this->_buffer.clear();
	return maxBuffSize;
}

void        BasicStream::drop()
{
	this->_buffer.clear();
}

void        BasicStream::dropAll()
{
	this->drop();
	this->mReader.clear();
}

void        BasicStream::flush()
{
	if (this->isReaderSet())
		this->mReader(*this);
	this->_buffer.clear();
}

void        BasicStream::close()
{	
	this->flush();
	if (this->mCloseReader.isSet())
		this->mCloseReader(*this);
	this->mClosed = true;
}

void        BasicStream::forceClose()
{
	if (this->mCloseReader.isSet())
		this->mCloseReader(*this);
	this->mClosed = true;
}

