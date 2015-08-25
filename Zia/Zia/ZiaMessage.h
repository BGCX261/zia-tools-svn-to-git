#pragma once

#include "api/IMessage.hpp"


namespace zia{

	class ZiaMessage :
		public zia::api::IMessage
	{
	public:
		ZiaMessage(zia::api::IConnection& connection);
		~ZiaMessage(void);
		ZiaMessage(const ZiaMessage&);
		ZiaMessage& operator=(const ZiaMessage&);
		virtual zia::api::IMessage*      newMessageAtStep(zia::api::HttpStepID stepId, zia::api::AStream& input);
		virtual zia::api::AStream*       newDataStream();
		virtual zia::api::AStream*       newResourceStream(zia::api::Resource,
		zia::api::FdCallback readingCallback = zia::api::FdCallback(),
		zia::api::FdCallback writingCallback = zia::api::FdCallback());
		virtual void					 forceDeleteStream(zia::api::AStream* stream);
	};
};

