#ifndef ITASK_H
#define ITASK_H

#include "Thread.h"

namespace thread{
	
	class ITask
		: public CThread
	{
	public:

		ITask(void)
			: CThread()
		{
		}

		virtual ~ITask(void)
		{
		}

		virtual void* run() = 0;
	};
};
#endif