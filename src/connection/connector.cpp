

#include "connector.h"
#include <string>
#include <memory>

namespace ARK
{
namespace Utilities
{
namespace Network
{
/**************************************************
* ARK::Utilities::Network::Connector
* Default: Empty Constructor
**************************************************/
Connector::Connector() : ip_(), port_() {}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Constructor
*
* @param: const char *const newIP
* @param: const int newPort
**************************************************/
Connector::Connector(
		const char *const newIP,
		const unsigned int newPort
)	:	port_(newPort)
{
	strncpy(this->ip_, newIP, sizeof(this->ip_) / sizeof(this->ip_[0]));
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Move Assignment Operator
*
* @param: Connector&& other
**************************************************/
Connector& Connector::operator=(Connector&& other)
{
	if (this != &other)
	{
		strncpy(this->ip_, other.ip_, sizeof(this->ip_) / sizeof(this->ip_[0]));
		this->port_ = other.port_;
	}
	return *this;
}
/*************************************************/

/**************************************************************************************************/

/**************************************************
* Manages directing the callback from
* the devices HTTPClient Library
**************************************************/
// TODO: add proper check for callback.
std::string Connector::callback(const char *const request)
{
	return this->http->get(this->ip_, this->port_, request);
}
/*************************************************/

};
};
};
