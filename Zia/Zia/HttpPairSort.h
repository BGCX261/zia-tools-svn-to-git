#pragma once

#include "api/IMessage.hpp"

namespace zia{
	namespace core{
		struct HttpPairSort
		{
			bool operator()(const zia::api::HttpStep::Pair& first, const zia::api::HttpStep::Pair& second) const;
		};
	}
}

