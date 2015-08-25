#pragma once


#ifndef WIN_32

namespace filesystem{
	namespace info{
		
		typedef unsigned long	fileInfos;

		enum type
		{
			NONE = -1,
			DIRECTORY,
			REGULAR_FILE,
		};
	};
};
#endif