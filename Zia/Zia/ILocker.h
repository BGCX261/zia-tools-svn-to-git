#ifndef ILOCKER_H
#define ILOCKER_H

namespace thread{
	class ILocker
	{
	public:
		enum	state_lock
		{
			LOCK = 0,
			UNLOCK,
			ALREADY_LOCK,
			NO_PERM,
		};

		ILocker(void){}
		virtual ~ILocker(void){}
		
		virtual void			lock() = 0;
		virtual void			unlock() = 0;
		virtual state_lock		state() const = 0;
	};

}

#endif
