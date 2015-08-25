#pragma once

#include <list>
#include "api/HttpStep.hpp"
#include "BasicStream.h"
#include "ZiaMessage.h"
#include "api/IConnection.hpp"

namespace zia{
	namespace core{
		
		class Linker
		{
		
		private:
			std::list<zia::api::AStream*>	_listStream;
			zia::ZiaMessage*				_message;

		public:
			Linker();
			~Linker(void);
			Linker&	operator=(const Linker&);
			Linker(const Linker&);
			void	operator()(zia::api::HttpStep::Pair&);
			zia::api::AStream*  stream() const;
			zia::api::AStream*	lastStream() const;
			void				message(zia::ZiaMessage*);
		};
	};
};