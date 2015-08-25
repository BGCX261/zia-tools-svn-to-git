#pragma once

#include "pthread.h"
namespace thread{

	class Locker;

	class ThreadCond
	{
		pthread_cond_t _cond;

	public:
		ThreadCond(void);
		~ThreadCond(void);
		void	wait(Locker& lock);
		void	signal();
		void	broadcast();
	};
};
