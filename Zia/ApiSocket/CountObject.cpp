#include "CountObject.h"

unsigned int CountObject::_compt = 0;

CountObject::CountObject(void)
{
	if (this->_compt == 0)
	{
		WSADATA WSAData;
		WSAStartup(MAKEWORD(2,0), &WSAData);
	}
	++this->_compt;

}


CountObject::~CountObject(void)
{
	//--this->_compt;
	//if (this->_compt == 0)
		//WSACleanup();
}