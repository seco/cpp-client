

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
		const char *const newHost,
		const unsigned int newPort,
		const char *const newFingerprint
) {
	this->connect(newHost, newPort, newFingerprint);
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
		this->connect(other.host_, other.port_, other.fingerprint_);
	};
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
	if (this->hasSSL)
	{
		return this->http->getHTTPS(this->host_, this->port_, this->fingerprint_, request);
	}
	else
	{
		return this->http->get(this->host_, this->port_, request);
	}
}
/*************************************************/

/**************************************************************************************************/

void Connector::connect(
		const char *const newHost,
		const unsigned int newPort,
		const char *const newFingerprint = ""
) {
	strncpy(this->host_, newHost, sizeof(this->host_) / sizeof(this->host_[0]));
	this->port_ = newPort;
	if (strcmp(newFingerprint, ""))
	{
		this->hasSSL = true;
		strncpy(this->fingerprint_, newFingerprint, sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));
	};

	// std::cout << newHost << std::endl;
	// std::cout << newPort << std::endl;
	// std::cout << newFingerprint << std::endl;

	// std::cout <<  << std::endl;
	// std::cout <<  << std::endl;
	// std::cout <<  << std::endl;
}

/**************************************************************************************************/

void Connector::disconnect()
{
	strncpy(this->host_, "\0", sizeof(this->host_) / sizeof(this->host_[0]));
	this->port_ = 0;
	if (this->hasSSL)
	{
		this->hasSSL = false;
		strncpy(this->fingerprint_, "\0", sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));
	};
}

/**************************************************************************************************/

std::string Connector::getConnection()
{
	char connectionStr[32] = { "\0" };
		std::strcpy(connectionStr, this->host_);
		std::strcat(connectionStr, ":");
	char portBuffer[5];
		sprintf(portBuffer, "%d", this->port_); 
		std::strcat(connectionStr, portBuffer);
	return connectionStr;
}

/**************************************************************************************************/

std::string Connector::getFingerprint() { return this->fingerprint_; }

/**************************************************************************************************/

};
};
};
