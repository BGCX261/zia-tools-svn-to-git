#include "HttpPairSort.h"
#include <iostream>

bool zia::core::HttpPairSort::operator()(const zia::api::HttpStep::Pair& first, const zia::api::HttpStep::Pair& second) const
{
	return first.mStep < second.mStep;
}