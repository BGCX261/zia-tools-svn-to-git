#pragma once

#include <string>
#include "BasicFile.h"
#include <map>
#include <list>
#include "SharedPointer.hpp"

namespace filesystem{
	
	class DocumentRoot
	
	{
	private:
		filesystem::BasicFile	_dir;


	public:
		DocumentRoot(void);
		~DocumentRoot(void);
		DocumentRoot(const DocumentRoot&);
		void	set(const FilePath& dirpath);
		const BasicFile		get(const std::string&) const;
		const BasicFile&	is() const;
	};
}