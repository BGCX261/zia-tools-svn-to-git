#ifndef _ICONNECTION_H_
#define _ICONNECTION_H_

#include "defines.hpp"
#include "Callback.hpp"
#include "AStream.hpp"
#include "DataTree.hpp"
#include "ILog.hpp"


#if defined(_WIN32) || defined(_WIN64)
#define WIN_32_MEAN_AND_LEAN
#include <WinSock2.h>
typedef int	ssize_t;
#include <Intsafe.h>
#endif

namespace zia{
	namespace api{
		
#if defined(_WIN32) || defined(_WIN64)
typedef HANDLE          Resource;
#else
		typedef int             Resource;
#endif
		typedef zia::api::Callback<ssize_t (Resource, void*, size_t) >     FdCallback;
	
		class IConnection
		{
		public:
			IConnection();
			virtual ~IConnection();
			IConnection(const IConnection&);
			IConnection&                operator=(const IConnection&);
			api::DataTree&              info();
			api::ILog&                  log();
			virtual void                close() = 0;
			virtual void                setFdReadCallback(api::FdCallback callback = api::FdCallback()) = 0;
			virtual void                setFdWriteCallback(api::FdCallback callback = api::FdCallback()) = 0;

		protected:
			ILog*                       mLog;
			DataTree*                   mInfos;
		};
	};
};
#endif /* _ICONNECTION_H_ */
