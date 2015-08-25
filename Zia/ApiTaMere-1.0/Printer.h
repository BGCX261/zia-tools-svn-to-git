#pragma once

#include <map>
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include <iostream>

namespace zia{
	namespace api{
		class Printer
		{
			const std::map< std::string, std::string>& _values;
			const std::map< std::string, std::list<std::string > >&	_listValues;

		public:
			Printer(const std::map< std::string, std::string>& values, const std::map< std::string, std::list<std::string > >& listValues);
			void	Printer::printValue(std::ostream& out) const;
			void	Printer::printList(std::ostream& out) const;
		};
	};
};

