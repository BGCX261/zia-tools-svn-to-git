#include "Printer.h"


zia::api::Printer::Printer(const std::map<std::string, std::string>& values, const std::map<std::string, std::list<std::string> >& listValues)
	: _values(values), _listValues(listValues)
{

}

void	zia::api::Printer::printValue(std::ostream& out) const
{
	std::map<std::string, std::string>::const_iterator it = this->_values.begin();
	std::map<std::string, std::string>::const_iterator end = this->_values.end();
	out << "Value : ";
	if (this->_values.empty())
	{
		out << " empty " << std::endl;
		return;
	}
	else
	{
		out << std::endl;
		for (; it != end; ++it)
			out << it->first << " : " << it->second << std::endl;
	}
}


void	zia::api::Printer::printList(std::ostream& out) const
{

	out << "List : ";
	if (this->_listValues.empty())
	{
		out << " empty " << std::endl;
		return;
	}
	else
	{
		std::map<std::string, std::list<std::string> >::const_iterator it = this->_listValues.begin();
		std::map<std::string, std::list<std::string> >::const_iterator end = this->_listValues.end();
		out << std::endl;
		for (; it != end; ++it)
		{
			out << it->first << " : [" ;
			std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<std::string>(out, ", "));
			out << "]" << std::endl;
		}
	}
}
