#include "AWorker.h"
#include "IThreadPool.h"
#include "Locker.h"

namespace thread{

	AWorker::AWorker(void)
	{
	}


	AWorker::~AWorker(void)
	{
	}


	AWorker::AWorker(IThreadPool* pool)
		: ITask(), _pool(pool), _poolLock(0)
	{

	}

	void	AWorker::condTask(ThreadCond* cond)
	{
		this->_condTask = cond;
	}

	void	AWorker::condPool(ThreadCond* cond)
	{
		this->_condPool = cond;
	}

	void	AWorker::poolLock(Locker* lock)
	{
		this->_poolLock = lock;
	}
};