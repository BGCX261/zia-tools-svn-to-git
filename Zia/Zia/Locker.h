#ifndef LOCKER_H
#define LOCKER_H

#include "pthread.h"
#include "ILocker.h"

namespace thread{
	
	class Locker
		: ILocker
	{

	private:

		pthread_mutex_t _mutex;
		state_lock			_state;
		Locker(const Locker&);
		Locker& operator=(const Locker&);
		friend	class ThreadCond;

	public:
		Locker(void);
		~Locker(void);
		virtual void			lock();
		virtual void			unlock();
		virtual state_lock		state() const;
	};
}

#endif