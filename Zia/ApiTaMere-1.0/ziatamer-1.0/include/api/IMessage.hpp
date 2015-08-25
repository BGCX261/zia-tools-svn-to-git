#ifndef _ZIA_API_IMESSAGE_H_
#define _ZIA_API_IMESSAGE_H_

#include <string>

#include "defines.hpp"
#include "IConnection.hpp"
#include "AStream.hpp"
#include "HttpStep.hpp"
#include "DataTree.hpp"
#include "ILog.hpp"

namespace zia{
	namespace api{
		
		class IMessage
		{
		public:

			IMessage(api::IConnection& connection);
			virtual ~IMessage();
			IMessage(const IMessage&);
			IMessage&                   operator = (const IMessage&);
			bool                        isParsed() const;
			api::DataTree&              http();
			api::DataTree&              httpResp();
			api::IConnection&           connection();
			api::ILog&                  log();
			virtual api::AStream*       newDataStream() = 0;
			virtual api::AStream*       newResourceStream(api::Resource resource,
				api::FdCallback readingCallback = api::FdCallback(),
				api::FdCallback writingCallback = api::FdCallback()) = 0;
			virtual void                forceDeleteStream(api::AStream* stream) = 0;
			virtual api::IMessage*      newMessageAtStep(api::HttpStepID stepId, api::AStream& input) = 0;

		protected:
			IConnection&                mConnection;
			bool                        mParsed;
			ILog*                       mLog;
			DataTree*                   mHttp;
			DataTree*                   mHttpResp;
		};
	};
};
#endif /* _ZIA_API_IMESSAGE_H_ */
