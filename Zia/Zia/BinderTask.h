#ifndef BINDER_TASK_H
#define BINDER_TASK_H

#include "ITaskFct.h"
#include "function.hpp"

namespace thread{

	class BinderTask
		: public ITaskFct
	{

		binder::function<void()>	_callback;

	public:
		BinderTask(binder::function<void()>& callback);
		~BinderTask(void);
		void	setCallback(binder::function<void()>&	_callback);
		virtual int		execute();
	};
};
#endif