

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "platform/platform.h"
#include "connection/http.h"

namespace ARK
{
namespace Utilities
{
namespace Network
{
/*************************************************
* ARK::Utilities::Network::Connectable
* @brief: Forward Declaration.
**************************************************/
class Connectable; 
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::Utilities::Network::Connector
**************************************************/
class Connector :
		virtual HTTPConnectable
{
	private:
		char host_[17];
		unsigned int port_;
		char fingerprint_[60] = { '\0' };

	public:
		Connector();
		Connector(const char *const newIP, const unsigned int newPort);
		Connector(const char *const newHost, const unsigned int newPort, const char *const newFingerprint);

		Connector& operator=(Connector&& other);

		std::string callback(const char* const request);
};
/*************************************************/

};
};
};

/**************************************************
* ARK::Utilities::Network::Connectable
* Inheritable Connector object
**************************************************/
class ARK::Utilities::Network::Connectable
{
	public:
		ARK::Utilities::Network::Connector netConnector;
};
/*************************************************/

#endif
