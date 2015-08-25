#include "HttpStep.hpp"

zia::api::HttpStep::Pair::Pair(zia::api::HttpStepID stepId, zia::api::HttpStep::Callback callback)
	  : mStep(stepId), mCallback(callback)
{

}

