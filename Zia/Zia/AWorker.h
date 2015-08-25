#ifndef AWORKER_H
#define AWORKER_H

#include "ITask.h"

namespace thread{

	class ThreadCond;
	class TaskWorker;
	class ITaskFct;
	class IThreadPool;
	class Locker;

	class AWorker
		: public ITask
	{
		AWorker(void);
		AWorker(const AWorker&);
		AWorker& operator=(const AWorker&);

	protected:

		Locker*			_poolLock;
		ThreadCond*		_condTask;
		ThreadCond*		_condPool;
		IThreadPool*	_pool;

	public:

		AWorker(IThreadPool* pool);
		virtual ~AWorker(void);


		void	condTask(ThreadCond*);
		void	condPool(ThreadCond*);
		void	poolLock(Locker*);
		virtual void* run() = 0;

	};
};

#endif