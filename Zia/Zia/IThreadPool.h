#ifndef ITHREAD_POOL
#define ITHREAD_POOL

namespace thread
{
	class ITaskFct;

	class	IThreadPool
	{

	public:
		IThreadPool(){}
		virtual ~IThreadPool(){}
		virtual bool	empty() const = 0;
		virtual void	addTask(ITaskFct*) = 0;
		virtual bool	addProcess() = 0;
		virtual ITaskFct* pop() = 0;
		virtual void	 join() = 0;
	};

};

#endif