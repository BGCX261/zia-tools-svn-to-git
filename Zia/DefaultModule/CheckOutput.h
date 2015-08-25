#ifndef __CHECKOUTPUT_H__
# define __CHECKOUTPUT_H__

#include "api/DataTree.hpp"

namespace	zia {
	namespace	module {

class	CheckOutput
{
public:
	enum	StatusCode
	{
		ALL = 0,
		Informational,
		Successful,
		Redirection,
		ClientError,
		ServerError
	};
	bool	checkStatusCode(const zia::api::DataTree& tree, StatusCode	code);
};

	}
}

#endif /* __CHECKOUTPUT_H__ */