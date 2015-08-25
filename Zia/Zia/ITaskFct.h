#ifndef ITASK_FCT_H
#define ITASK_FCT_H

namespace thread{
	class ITaskFct
	{
	public:

		ITaskFct(void)
		{

		}
		virtual ~ITaskFct(void)
		{
		}

		virtual int		execute() = 0;
	};
};

#endif
