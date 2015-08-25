#include "ConnectionBase.h"


zia::ConnectionBase::ConnectionBase()
	: IConnection(), _socket(0)
{
	this->mInfos = new zia::api::DataTree();
}



zia::ConnectionBase::~ConnectionBase(void)
{

}

zia::ConnectionBase::ConnectionBase(const zia::ConnectionBase& other)
	: _readerCallback(other._readerCallback),  _writerCallback(other._writerCallback), _socket(other._socket)
{
	 this->mInfos = other.mInfos; 
     this->mLog = other.mLog;
}

zia::ConnectionBase& zia::ConnectionBase::operator=(const zia::ConnectionBase& other)
{
	this->mInfos = other.mInfos;
	this->mLog = other.mLog;
	this->_readerCallback = other._readerCallback;
	this->_writerCallback = other._writerCallback;
	this->_socket = this->_socket;
	return *this;
}

void               zia::ConnectionBase::setFdReadCallback(zia::api::FdCallback callback)
{
	this->_readerCallback = callback;
}

void                zia::ConnectionBase::setFdWriteCallback(zia::api::FdCallback callback)
{
	this->_writerCallback = callback;
}

void						  zia::ConnectionBase::callSocketReader(zia::api::AStream* stream)
{
	
	if (stream != 0)
	{
		if (this->_readerCallback.isSet() == true)
		{
			this->_readerCallback((zia::api::Resource)this->_socket->native(), (void*)stream, 0);
		}
	}
}

void						 zia::ConnectionBase::callSocketWriter(zia::api::AStream* stream)
{
		if (stream != 0)
		{
			if (this->_writerCallback.isSet() == true)
			{
				this->_writerCallback((zia::api::Resource)this->_socket->native(), (void*)stream, 0);
			}
		}
}



void				 zia::ConnectionBase::close()
{
	this->_writerCallback.clear();
	this->_socket->close();
}

const ip::tcp::socket&		zia::ConnectionBase::socket() const 
{
	return *this->_socket;
}

void		zia::ConnectionBase::socket(ip::tcp::socket& newsock) 
{
	this->_socket = &newsock;
	this->mInfos->mSubs["connection"].clear();
	this->mInfos->mSubs["connection"]["local"]["port"] = this->_socket->local().portToString();
	this->mInfos->mSubs["connection"]["local"]["ip"] = this->_socket->local().address().toString();
	this->mInfos->mSubs["connection"]["remote"]["port"] = this->_socket->remote().portToString();
	this->mInfos->mSubs["connection"]["remote"]["ip"] = this->_socket->remote().address().toString();
}