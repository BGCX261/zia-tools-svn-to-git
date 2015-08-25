#include "Thread.h"
#include <iostream>


namespace thread{
	CThread::CThread(void)
		: _id(), _attr(0), _prev(none), _current(cancel_enable) 
	{

	}


	CThread::~CThread(void)
	{


	}

	void	CThread::create()
	{
		pthread_create(&this->_id, &this->_attr, CThread::make,  static_cast<void*>(this)); 
	}

	void	CThread::cancel(CThread* ptr)
	{
		if (ptr == 0)
			pthread_cancel(this->_id);
		else
			pthread_cancel(ptr->id());
	}

	void	CThread::setCancelState(cancel_state state)
	{
		pthread_setcancelstate(state, reinterpret_cast<int*>(&this->_prev));
	}

	void	CThread::error(int error) const
	{
		switch (error)
		{
		case ESRCH:
			throw std::exception("Aucun thread ne correspond à celui passé en argument");
			break;
		case EINVAL:
			throw std::exception("Le thread a été détaché ou un autre thread attend déjà la fin du même thread.");
			break;
		case EDEADLK:
			throw std::exception("Le thread passé en argument correspond au thread appelant");
			break;
		}
	}

	int		CThread::join(CThread* ptr)
	{
		void	*thread_return;
		int		check = 0;
		if (ptr == 0)
			check = pthread_join(this->_id, &thread_return);
		else
			check = pthread_join(ptr->id(), &thread_return);
		if (check != 0)
			this->error(check);
		int* state = static_cast<int*>(thread_return);
		return check;
	}

	pthread_t	CThread::id() const
	{
		return this->_id;
	}

	void* CThread::make(void* arg)
	{
		CThread* th = static_cast<CThread*>(arg);
		return th->run();
	}

	cancel_state	CThread::prevState() const
	{
		return this->_prev;
	}

	cancel_state	CThread::currentState() const
	{
		return this->_current;
	}

	bool		CThread::operator==(CThread& other) const
	{
		return pthread_equal(this->id(), other.id()) != 0;
	}
	bool		CThread::operator!=(CThread& other) const
	{
		return !(*this == other);
	}

	void	CThread::attribut(const pthread_attr_t& attr)
	{
		this->_attr = attr;
	}

	void	CThread::exit()
	{
		void*	retval;
		pthread_exit(&retval);
	}
};