#include "ZiaMessage.h"
#include "BasicStream.h"
#include "Printer.h"

zia::ZiaMessage::ZiaMessage(zia::api::IConnection& connection)
	: zia::api::IMessage(connection)
{
	this->mHttp = new zia::api::DataTree();
	this->mHttpResp = new zia::api::DataTree();
}

zia::ZiaMessage::ZiaMessage(const ZiaMessage& other)
	: zia::api::IMessage(other.mConnection)
{
	this->mHttp = other.mHttp;
	this->mHttpResp = other.mHttpResp;
	this->mLog = other.mLog;
	this->mParsed = other.mParsed;
}

zia::ZiaMessage& zia::ZiaMessage::operator=(const ZiaMessage& other)
{
	this->mConnection = other.mConnection;
	this->mHttp = other.mHttp;
	this->mHttpResp = other.mHttpResp;
	this->mLog = other.mLog;
	this->mParsed = other.mParsed;
	return *this;
}


zia::ZiaMessage::~ZiaMessage(void)
{
	delete this->mHttp;
	delete this->mHttpResp;
}

zia::api::AStream*       zia::ZiaMessage::newDataStream()
{
	return new zia::BasicStream();
}

zia::api::AStream*       zia::ZiaMessage::newResourceStream(zia::api::Resource handle,
	zia::api::FdCallback readingCallback,
	zia::api::FdCallback writingCallback)
{
	zia::api::AStream* stream = new zia::BasicStream();
	return stream;
}


 void                zia::ZiaMessage::forceDeleteStream(zia::api::AStream* stream)
{
	delete stream;
}

zia::api::IMessage*      zia::ZiaMessage::newMessageAtStep(zia::api::HttpStepID stepId, zia::api::AStream& input)
{
	return new ZiaMessage(this->mConnection);
}