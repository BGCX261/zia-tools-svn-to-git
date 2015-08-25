#include "api/DataRep.hpp"
#include "Printer.h"

zia::api::DataRep::DataRep()
{

}

zia::api::DataRep::~DataRep()
{


}

bool                        zia::api::DataRep::hasValue(const std::string& key) const
{
	std::map< std::string, std::string >::const_iterator it;
	it = this->mValues.find(key);
	if (it != this->mValues.end() && it->second.empty() == false)
		return true;
	return false;
}

/*!
* \brief Check if it has the \a key.
*
* An empty list is considered as non-existent.
*
* \return true if \a key exists.
{*/
bool                          zia::api::DataRep::hasList(const std::string& key) const

	std::map< std::string, std::list< std::string > >::const_iterator it;
	it = this->mLists.find(key);
	if (it != this->mLists.end() && it->second.empty() == false)
		return true;
	return false;		 
}

/*!
* \brief Get a value
*
* \return The value if \a key exists,
* an empty string if \a key doesnot exist.
*/
const std::string&            zia::api::DataRep::value(const std::string& key) const
{
	std::map< std::string, std::string>::const_iterator it;
	it = this->mValues.find(key);
	if (it != this->mValues.end())
		return it->second;
	return "";
}

/*!
* \brief Set a value
*
*/
void                         zia::api::DataRep::value(const std::string& key,
	const std::string& value)
{
	this->mValues.insert(std::pair<std::string, std::string>(key, value));
}

/*!
* \brief Get reference on a list.
*
* If \a key doesnot exist, the \a key is create with
* an empty list.
*
* \return The list.
*/
std::list< std::string >&     zia::api::DataRep::list(const std::string& key)
{

	return this->mLists[key];
}

/*!
* \brief Get a const reference on a list.
*
* \return The list, an empty list if \a key does not exist.
*/
const std::list< std::string >&   zia::api::DataRep::const_list(const std::string& key) const
{
	std::map<std::string, std::list< std::string > >::const_iterator it = this->mLists.find(key);
	if (it != this->mLists.end())
		return it->second;
	const std::list<std::string> p;
	return p;
}

/*!
* \brief Remove all datas
*/
void                          zia::api::DataRep::clear()
{
	this->mLists.clear();
	this->mValues.clear();
}

/*!
* \brief Print datas.
*
* \param out Where datas will be print.
*/
void                          zia::api::DataRep::print(std::ostream& out) const
{
	zia::api::Printer	printer(this->mValues, this->mLists);
	
	printer.printValue(out);
	printer.printList(out);
}

