#include "Locker.h"

namespace thread{
	Locker::Locker(void)
		: _mutex(PTHREAD_MUTEX_INITIALIZER)
	{

	}


	Locker::~Locker(void)
	{

	}

	void			Locker::lock()
	{
		int check = pthread_mutex_lock(&this->_mutex);
		if (check == 0)
			this->_state = LOCK;
		else
			this->_state = ALREADY_LOCK;
	}

	void			Locker::unlock()
	{
		int check = pthread_mutex_unlock(&this->_mutex);
		if (check == 0)
			this->_state = UNLOCK;
		else
			this->_state = NO_PERM;
	}

	Locker::state_lock	Locker::state() const
	{
		return this->_state;
	}
};