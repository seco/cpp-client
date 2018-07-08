

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
Connector::Connector() : host_(), port_(), fingerprint_() {};
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
)	:	port_(newPort), fingerprint_()
{
	strncpy(this->host_, newIP, sizeof(this->host_) / sizeof(this->host_[0]));
}
/*************************************************/


/**************************************************************************************************/

Connector::Connector(
		const char *const newHost,
		const unsigned int newPort,
		const char *const newFingerprint
)	:	port_(newPort)
{
	strncpy(this->host_, newHost, sizeof(this->host_) / sizeof(this->host_[0]));
	strncpy(this->fingerprint_, newFingerprint, sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));

};

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
		strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
		this->port_ = other.port_;
		strncpy(this->fingerprint_, other.fingerprint_, sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));
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
	if (this->fingerprint_[0] != '0')
	{
		return this->http->getHTTPS(this->host_, this->port_, this->fingerprint_, request);
	}
	else
	{
		return this->http->get(this->host_, this->port_, request);
	}
}
/*************************************************/

};
};
};
