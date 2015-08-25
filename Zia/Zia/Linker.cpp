#include "Linker.h"


zia::core::Linker::Linker()
	: _message(0), _listStream()
{
	
}

zia::core::Linker::~Linker(void)
{


}

zia::core::Linker::Linker(const zia::core::Linker& other)
	: _message(other._message), _listStream(other._listStream)
{

}


zia::core::Linker& zia::core::Linker::operator=(const zia::core::Linker& other)
{
	this->_message = other._message;
	this->_listStream = other._listStream;
	return *this;
}

void	zia::core::Linker::operator()(zia::api::HttpStep::Pair& callBackPair)
{
	if (this->_listStream.empty())
		this->_listStream.push_back(new zia::BasicStream());
	if (this->_message != 0)
		this->_listStream.push_back(callBackPair.mCallback(*this->_message , this->_listStream.back()));
}


zia::api::AStream*	zia::core::Linker::stream() const
{
	return this->_listStream.front();
}

zia::api::AStream*	zia::core::Linker::lastStream() const
{
	return this->_listStream.back();
}


void					zia::core::Linker::message(zia::ZiaMessage* msg)
{
	this->_message = msg;
}