#include "BinderTask.h"

namespace thread{
	BinderTask::BinderTask(binder::function<void()>& callback)
		: ITaskFct(), _callback(callback)
	{
	}


	BinderTask::~BinderTask(void)
	{
	}

	void	BinderTask::setCallback(binder::function<void()>& callback)
	{
		this->_callback = callback;
	}

	int		BinderTask::execute()
	{
		this->_callback();
		return 0;
	}
};