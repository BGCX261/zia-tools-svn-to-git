#ifndef _ZIA_API_ICONF_H_
#define _ZIA_API_ICONF_H_

#include <string>

#include "defines.hpp"
#include "DataTree.hpp"
#include "ILog.hpp"

namespace zia{
	namespace api{

		class IConf : public api::DataTree
		{
		public:
			IConf(){}
			virtual ~IConf(){}
		};
	};
};

#endif /* _ZIA_API_ICONF_H_ */
