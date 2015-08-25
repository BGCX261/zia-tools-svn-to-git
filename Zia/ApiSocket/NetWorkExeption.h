#ifndef NETWORK_EXCEPTION_H
#define NETWORK_EXCEPTION_H

#include <exception>
#include <string>

namespace ip
{
	class NetWorkExeption
	{
	public:
		enum EnumLvl
		{
			Low		= 0,
			Medium,
			Hight
		};

		enum From
		{
			CONNECT = 0,
			TCP,
			UDP,
			ACCEPT,
			SOCK,
			LISTEN,
			BIND,
			SELECT,
			CLOSE,
			SHUT
		};

		NetWorkExeption(int errorId,  unsigned long,  int lvl);
		virtual ~NetWorkExeption(void) throw();
		virtual const char* what() const throw();
		int	from() const;
	private:
		NetWorkExeption(void);
		unsigned long	_lasterror;
		int		_lvl;
		int		_id;
	};
}

#endif