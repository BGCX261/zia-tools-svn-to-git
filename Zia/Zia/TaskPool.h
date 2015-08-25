#ifndef TASK_POOL_H
#define TASK_POOL_H


#include <queue>
#include <list>
#include "pthread.h"
#include "Locker.h"
#include "ThreadCond.h"
#include "IThreadPool.h"

namespace thread{

	class ITaskFct;
	class AWorker;


	class TaskPool
		: public IThreadPool
	{
	private:
		int		_nbStart;
		int		_maxTask;

		Locker		_mutex;
		ThreadCond	_condPool;
		ThreadCond	_condTask;

		std::list<AWorker*>		_process;
		std::queue<ITaskFct*>	_taskFct;
		void					createNewProcess();
		
	public:
		
		TaskPool(int nbStart, int maxTask = PTHREAD_THREADS_MAX);
		virtual ~TaskPool(void);
		
		virtual bool	empty() const;
		virtual void	addTask(ITaskFct*);
		virtual bool	addProcess();
		virtual ITaskFct* pop();
		virtual void	join();
		
		int				maxProcess() const;
		int				maxProcess(int max);
		void			run();
		void			init();
		void			kill();
	};
};

#endif