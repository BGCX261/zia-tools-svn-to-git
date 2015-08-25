#include <iostream>
#include "TaskWorker.h"
#include "Locker.h"
#include "IThreadPool.h"
#include "ITaskFct.h"


namespace thread{

	TaskWorker::TaskWorker(IThreadPool* pool)
		: AWorker(pool)
	{

	}

	TaskWorker::~TaskWorker(void)
	{

	}

	void* TaskWorker::run()
	{
		while (true)
		{
			this->_poolLock->lock();
			if (this->_pool->empty() == true)
				this->_condTask->wait(*this->_poolLock);
			this->_poolLock->unlock();
			ITaskFct *fct = this->_pool->pop();
			if (fct != 0)
			{
				fct->execute();
				delete fct;
			}
		}
		return 0;
	}
};