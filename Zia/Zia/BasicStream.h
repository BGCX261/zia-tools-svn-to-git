#pragma once
#include "api/AStream.hpp"

namespace zia
{
	class BasicStream
		: public zia::api::AStream
	{
	private:
		std::string	_buffer;
	public:
		BasicStream(void);
		virtual ~BasicStream(void);
		virtual int         callReader();
		virtual bool        canRead() const;
		virtual void        write(const std::string& str);
		virtual void        write(const char* buff, size_t buffSize);
		virtual size_t      read(char* buff, size_t maxBuffSize);
		virtual void        drop();
		virtual void        dropAll();
		virtual void        flush();
		virtual void        close();
		virtual void        forceClose();
	};
};
