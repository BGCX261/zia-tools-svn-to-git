#pragma once

#include <fstream>
#include <string>
#include "fileinfos.h"
#include "FilePath.h"

namespace filesystem
{
	class BasicFile
	{
		filesystem::info::fileInfos	_infos;
		FilePath					_filePath;

		void						getFileInfos();
		
	public:
		BasicFile(void);
		BasicFile(const std::string& filename);
		BasicFile(const FilePath& filename);
		~BasicFile(void);


		BasicFile(const BasicFile&);
		BasicFile&	operator=(const BasicFile&);
		BasicFile&	operator=(const std::string&);
		BasicFile&	operator=(const FilePath& filepath);

		bool	operator==(const  BasicFile& filepath) const;
		bool	operator!=(const  BasicFile& filepath) const;

		std::fstream	fstream(std::ios_base::openmode	mode = std::ios_base::in | std::ios_base::out) const;
		std::ifstream   ifstream(std::ios_base::openmode mode = std::ios_base::in) const;
		
		void			path(const std::string&);
		const FilePath&	path() const;
		
		filesystem::info::type	type() const;
	};
};
