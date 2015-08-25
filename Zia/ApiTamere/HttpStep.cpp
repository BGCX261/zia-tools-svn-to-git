#include "api/HttpStep.hpp"

zia::api::HttpStep::Pair::Pair(zia::api::HttpStep::ID stepId, zia::api::HttpStep::Callback callback)
	  : mStep(stepId), mCallback(callback)
{

}

