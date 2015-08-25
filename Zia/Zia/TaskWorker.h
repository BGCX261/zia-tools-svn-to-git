#ifndef TASK_WORKER_H
#define TASK_WORKER_H

#include "ITask.h"
#include "AWorker.h"
#include  "ThreadCond.h"

namespace thread{
	

	class TaskWorker
		: public AWorker
	{
	public:
		TaskWorker(IThreadPool*);
		~TaskWorker(void);
		virtual void* run();
	};

};
#endif
