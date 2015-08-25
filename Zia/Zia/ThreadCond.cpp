#include "ThreadCond.h"
#include "Locker.h"

namespace thread{

	ThreadCond::ThreadCond(void)
		: _cond(PTHREAD_COND_INITIALIZER)
	{

	}

	ThreadCond::~ThreadCond(void)
	{
	}

	void	ThreadCond::wait(Locker& lock)
	{
		pthread_cond_wait(&this->_cond, &lock._mutex);
	}

	void	ThreadCond::signal()
	{
		pthread_cond_signal(&this->_cond);
	}
	
	void	ThreadCond::broadcast()
	{
		pthread_cond_broadcast(&this->_cond);
	}
};