#ifndef _ZIA_API_HTTPSTEP_H_
#define _ZIA_API_HTTPSTEP_H_

#include "defines.hpp"
#include "Callback.hpp"
#include "AStream.hpp"

namespace zia{
	namespace api{

		enum HttpStepID
		{

			STEP_NONE = 0,
			STEP_IN,
			STEP_IN_POST,
			STEP_PARSER_PRE,
			STEP_PARSER,
			STEP_PARSER_POST,
			STEP_EXEC_PRE,
			STEP_EXEC,
			STEP_EXEC_POST,
			STEP_RAWER_PRE,
			RAWER,
			STEP_RAWER_POST,
			STEP_OUT_PRE,
			STEP_OUT
		};

		class IMessage;
		namespace HttpStep
		{

			typedef zia::api::Callback< AStream* (IMessage&, AStream*) >  Callback;

			class Pair
			{
			public:
				HttpStepID          mStep;
				Callback  mCallback;
				Pair(HttpStepID stepId, HttpStep::Callback callback);
			};
		};
	};
};
#endif /* _ZIA_API_HTTPSTEP_H_ */
