#pragma once


#include <string>
#include "ValidSeparator.h"

namespace filesystem{
	
	class FilePath
	{
		std::string	 _path;

	public:

		FilePath(const std::string& path);
		FilePath(void);
		~FilePath(void);
		FilePath(const FilePath& other);
		FilePath& operator=(const FilePath& other);
		FilePath& operator=(const std::string& path);
		FilePath& operator+=(const FilePath& other);
		bool		operator==(const FilePath& filepath) const;
		bool		operator==(const std::string& filepath) const;

		bool		operator!=(const FilePath& filepath) const;
		bool		operator!=(const std::string& filepath) const;
		
		
		void	set(const std::string& path);
		const	std::string&	toString() const;

		std::string basename(char separator = PATH_SEPARATOR) const;
		std::string dirname(char separator = PATH_SEPARATOR) const;

		static FilePath	toValidPath(const std::string&);
	};

};