#include <string>

#include "MPMessage.h"

MPMessage::MPMessage(const std::string& msg)
	: _curMsg(msg), _iniMsg(msg)
{
}

MPMessage::MPMessage(const MPMessage& msg)
	: _iniMsg(msg._iniMsg), _curMsg(msg._curMsg)
{
}

std::string&	MPMessage::getCurMsg()
{
	return this->_curMsg;
}

const std::string&	MPMessage::getIniMsg() const
{
	return this->_iniMsg;
}

void	MPMessage::refreshMessage()
{
	this->_curMsg = this->_iniMsg;
}

void	MPMessage::updateMessage(const std::string& refMsg)
{
	this->_curMsg = refMsg;
}

void	MPMessage::updateMessage(const MPMessage& refMsg)
{
	//this->_curMsg = refMsg.getCurMsg();
}
