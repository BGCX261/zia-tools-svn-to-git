#include "AStream.hpp"

zia::api::AStream::AStream()
	: mExpectedSize(500), mClosed(false), mReader()

{

}

zia::api::AStream::~AStream()
{

}

void                    zia::api::AStream::setReader(Reader streamReader)
{ 
	this->mReader = streamReader; 
}

void             zia::api::AStream::setCloseReader(Reader streamCloseReader)
{ 
	this->mCloseReader = streamCloseReader;
}

bool                    zia::api::AStream::isReaderSet() const
{ 
	return this->mReader.isSet();
}

bool                    zia::api::AStream::isCloseReaderSet() const
{
	return this->mCloseReader.isSet();
}

void                    zia::api::AStream::setExpectedReadSize(size_t readingSize)
{ 
	this->mExpectedSize = readingSize; 
}

bool                    zia::api::AStream::isClosed() const 
{ 
	return this->mClosed;
}
