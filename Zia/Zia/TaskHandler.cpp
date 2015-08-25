#include "TaskHandler.h"
#include <iostream>

namespace thread{

	TaskHandler::TaskHandler(int i)
		: _i(i)
	{
	}


	TaskHandler::~TaskHandler(void)
	{
	}

	int TaskHandler::execute()
	{
		std::cout << "operator numero " << this->_i << std::endl;
		return this->_i;
	}
};