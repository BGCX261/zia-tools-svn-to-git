#include "IMessage.hpp"

zia::api::IMessage::IMessage(zia::api::IConnection& connection)
	: mConnection(connection), mParsed(false), mLog(0), mHttp(0), mHttpResp(0)
{}

zia::api::IMessage::~IMessage()
{
}

/*!
* \brief Check if the http header is parsed.
*
* \return true if the http header datas are ready for reading,
* false if the http header is not yet totaly parsed.
*/

bool                        zia::api::IMessage::isParsed() const
{
	return this->mParsed;
}

/*!
* \brief Get request http header datas.
*/
zia::api::DataTree&               zia::api::IMessage::http()
{
	return *this->mHttp;
}

/*!
* \brief Get response http header datas.
*
*/
zia::api::DataTree&               zia::api::IMessage::httpResp()
{
	return *this->mHttpResp;
}

/*!
* \brief Get the IConnection.
*/
zia::api::IConnection&           zia::api::IMessage::connection()
{
	return this->mConnection;
}

