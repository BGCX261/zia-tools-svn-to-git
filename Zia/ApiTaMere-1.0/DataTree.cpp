#include "DataTree.hpp"
#include <iterator>

#include "Callback.hpp"

zia::api::DataTree::DataTree()
{

}

zia::api::DataTree::~DataTree()
{

}

zia::api::DataTree::operator const std::string& () const
{
	return this->mValue;
}

zia::api::DataTree&               zia::api::DataTree::operator=(const DataTree& dataTree)
{
	this->mList = dataTree.mList;
	this->mSubs = dataTree.mSubs;
	this->mValue = dataTree.mValue;
	return *this;
}

zia::api::DataTree&               zia::api::DataTree::operator=(const std::string& value)
{
	this->mValue = value;
	this->mList.push_back(mValue);
	return *this;
}

const zia::api::DataTree&         zia::api::DataTree::operator[](const std::string& key) const
{
	return this->mSubs.at(key);
}

zia::api::DataTree&         zia::api::DataTree::operator[](const std::string& key)
{
	return this->mSubs[key];
}

bool                     zia::api::DataTree::operator==(const std::string& right) const
{
	
	return this->mValue.compare(right) == 0;
}

bool                     zia::api::DataTree::operator!=(const std::string& right) const
{
	return !(*this == right);
}

const zia::api::DataTree&         zia::api::DataTree::c() const
{
	return *this;
}

const std::string&      zia::api::DataTree::v() const
{
	return this->mValue;
}

bool                    zia::api::DataTree::has(const std::string& key) const
{
	return this->mSubs.find(key) != this->mSubs.end();
}

 const zia::api::DataTree&         zia::api::DataTree::get(const std::string& key) const
 {
	 return this->mSubs.at(key);
 }

 zia::api::DataTree& zia::api::DataTree::operator+=(const DataTree&  dataTree)
 {
	return *this;
 }

void                    zia::api::DataTree::clear()
{
	this->mList.clear();
	this->mSubs.clear();
	this->mValue.clear();
}

void                    zia::api::DataTree::print(std::ostream& out, int indentLevel) const
{
	std::cout << "Value" << std::endl;
	std::cout << this->mValue << std::endl;
	std::cout << "List Values" << std::endl;
	std::copy(this->mList.begin(), this->mList.end(), std::ostream_iterator<std::string>(out, ", "));
}
