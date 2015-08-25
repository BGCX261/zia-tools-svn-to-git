#ifndef _ZIA_API_IMODULE_H_
#define _ZIA_API_IMODULE_H_

#include "defines.hpp"
#include "IMessage.hpp"
#include "Callback.hpp"
#include "HttpStep.hpp"

namespace zia{
	namespace api{

		class IModule
		{
		public:
			IModule() { }
			virtual ~IModule() { }
			virtual void        module_delete(api::IConnection& connection) = 0;
		};
	};
};
#endif /* _ZIA_API_IMODULE_H_ */
