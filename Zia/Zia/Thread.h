#ifndef CTHREAD_H
#define CTHREAD_H

#include "pthread.h"

namespace thread{

	enum	cancel_state
	{
		none = -1,
		cancel_enable = PTHREAD_CANCEL_ENABLE,
		cancel_disable = PTHREAD_CANCEL_DISABLE
	};

	class CThread
	{
		pthread_t		_id;
		cancel_state	_prev;
		cancel_state	_current;

		pthread_attr_t	_attr;
		static	void*	make(void*);
		void			error(int error) const;
		CThread(const CThread&);
		CThread&	operator=(const CThread&);
		typedef void* (*routine) (void *);

	public:

		CThread(void);
		virtual ~CThread(void);

		void	attribut(const pthread_attr_t&);
		void	start();
		void	create();
		void	cancel(CThread* ptr = 0);
		void	setCancelState(cancel_state	state);
		int		join(CThread* ptr = 0);

		bool			operator==(CThread&) const;
		bool			operator!=(CThread&) const;

		pthread_t		id() const;
		cancel_state	prevState() const;
		cancel_state	currentState() const;
		virtual	void*	run() = 0;
		static	void	exit();

	};
}

#endif // CTHREAD_H
