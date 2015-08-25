#include <iostream>
#include <algorithm>
#include <functional>
#include "TaskPool.h"
#include "TaskWorker.h"
#include "ITaskFct.h"
#include "TaskHandler.h"
#include "AWorker.h"

namespace thread{

	struct	KillThread
	{
		template <class T> void operator ()(T* p) const 
		{ 
			p->cancel();
			delete p;
			p = NULL;
		} 
	};

	struct	JoinThread
	{
		void operator ()(CThread* thread) const 
		{ 
			thread->join();
		} 
	};

	TaskPool::TaskPool(int nbStart, int maxTask)
		: IThreadPool(), _nbStart(nbStart), _maxTask(maxTask), _process(), _taskFct()
	{
		this->init();
	}

	TaskPool::~TaskPool(void)
	{
		this->kill();
	}

	int		TaskPool::maxProcess() const
	{
		return this->_maxTask;
	}

	int		TaskPool::maxProcess(int max)
	{
		return this->_maxTask;
	}

	void		TaskPool::createNewProcess()
	{
		TaskWorker *new_task = new TaskWorker(this);
		new_task->poolLock(&this->_mutex);
		new_task->condPool(&this->_condPool);
		new_task->condTask(&this->_condTask);
		new_task->create();
		this->_process.push_back(new_task);
	}

	bool		TaskPool::addProcess()
	{
		if (this->_nbStart < this->maxProcess())
		{
			this->createNewProcess();
			return true;
		}
		return false;
	}
	void		TaskPool::init()
	{
		if (this->_nbStart > this->maxProcess())
			this->_maxTask = this->_nbStart;
		for (int i = 0; i < this->_nbStart; i++)
			this->createNewProcess();
	}

	void	TaskPool::run()
	{
		std::list<AWorker*>::iterator	it = this->_process.begin();
		std::list<AWorker*>::iterator	end = this->_process.end();
		for (; it != end; ++it)
		{
			(*it)->join();
		}

	}
	void	TaskPool::kill()
	{
		this->_mutex.lock();
		std::for_each(this->_process.begin(), this->_process.end(), KillThread());
		this->_process.clear();
		this->_mutex.unlock();
	}

	bool	TaskPool::empty() const
	{
		return this->_taskFct.empty();
	}

	void	TaskPool::addTask(ITaskFct* taskFct)
	{
		this->_mutex.lock();
		this->_taskFct.push(taskFct);
		this->_mutex.unlock();
		this->_condTask.broadcast();
	}

	ITaskFct*	TaskPool::pop()
	{
		ITaskFct *fct = 0;
		this->_mutex.lock();
		if (this->_taskFct.empty() == false)
		{
			fct = this->_taskFct.front();
			this->_taskFct.pop();
			this->_mutex.unlock();
			return fct;
		}
		this->_mutex.unlock();
		return 0;
	}

	void	TaskPool::join()
	{
		std::for_each(this->_process.begin(), this->_process.end(), JoinThread());
	}
};