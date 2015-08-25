#ifndef TASK_HANDLER_H
#define TASK_HANDLER_H
#include "ITaskFct.h"

namespace thread
{
	class TaskHandler
		: public ITaskFct
	{
		int	_i;
	public:
		TaskHandler(int i);
		~TaskHandler(void);
		virtual int execute();
	};
};

#endif